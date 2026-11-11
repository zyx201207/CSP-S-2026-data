#include <iostream>
using namespace std;
int main (){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int room1,room2;
    string sit1,sit2;
    cin>>room1;
    cin>>sit1;
    cin>>room2;
    cin>>sit2;
    if(room1==room2){
        cout<<"1"<<" ";
    }
    else{
         cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" ";
         return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
    }
