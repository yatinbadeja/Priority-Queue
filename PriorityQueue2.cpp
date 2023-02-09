#include <iostream>
using namespace std;
class Pqueue{
    public:
    int *arr;
    int *priority;
};
class PriorityQueue : public Pqueue{
    public:
    int front;
    int rear;
    int size;

    PriorityQueue(int size){
        this->size=size;
        front=-1;
        rear=-1;
        arr = new int [size];
        priority = new int [size];
    }
    void insertion(int data,int pri){
        if(rear == (size-1)){
            cout<<"Priority Queue is Full"<<endl;
            return;
        }
        else if(front==-1 && rear ==-1){
            rear++;
            front++;
            arr[rear]=data;
            priority[rear]=pri;
            return;
        }
        rear++;
        arr[rear]=data;
        priority[rear]=pri;
    }
    void display(){
        cout<<"The Priority Queue is : ";
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
        cout<<"The Priority order of Queue is : ";
        for(int i=front;i<=rear;i++){
            cout<<priority[i]<<" ";
        }cout<<endl;
    }
    void deletion(){
        int maxpriorty=priority[0];
        int index=0;
        for(int i=0;i<size;i++){
            if(maxpriorty<priority[i]){
                maxpriorty=priority[i];
                index=i;
            }
        }
        for(int i=index;i<size;i++){
            priority[i]=priority[i+1];
            arr[i]=arr[i+1];
        }
    }
};
int main(){
    PriorityQueue Queue1(3);
    Queue1.insertion(45,1);
    Queue1.insertion(54,6);
    Queue1.insertion(65,1);
    Queue1.insertion(65,3);
    Queue1.deletion();
    Queue1.deletion();
    Queue1.display();
}