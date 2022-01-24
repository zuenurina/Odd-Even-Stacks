#include <iostream>
#include<stack>
using namespace std;

class Stack{
  struct Data{
  int no;
  Data *next;
  };
 
  public: 
  Stack(){
   head = NULL;
  }
 
  void push(int no){ 
    Data *a;
    a = new Data();
    a->no = no;
    a->next = head;
    head = a;
  }
 
  void pop(){
    Data *b;
    b = new Data();
    while (head != NULL){
      b = head; 
      head = b->next;
      free(b);
    }
    
    cout << "\nRemoving all numbers ~~~\n";
    if (head == NULL){
      cout << "[Result] All number have been deleted.\n";
    }
  } 

  void analysis(){
    Data *d;
    d = head; 
    int i = 1, countEven = 0, countOdd = 0;
    while (d != NULL){
      if (d->no % 2 == 0){
        cout << "Value " << i << ": " << d->no << " (Even)" << endl;
        countEven = countEven + 1;
      }
      else {
        cout << "Value " << i << ": " << d->no << " (Odd)" << endl;
        countOdd = countOdd + 1;
      }
      i++;
      d = d->next;
    }

    cout << "Total even value: " << countEven << endl;
    cout << "Total odd value: " << countOdd << endl;
  }

  private:
  Data *head;
};

int main() {
  int size, val;
  Stack obj;

  cout << "Enter total value to insert: ";
  cin >> size;

  for (int i = 1; i <= size; i++){
    cout << "Enter a value : ";
    cin >> val;
    obj.push(val);
  }
 
  cout << endl << "::Analysis::" << endl;
  obj.analysis();
  obj.pop();
  
  cout << "\nEnd of program";
  return 0;
}
