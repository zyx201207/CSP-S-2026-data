#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int car1,car2,lis1,lis2;
    char seat1,seat2;
    cin >> car1 >> lis1 >> seat1;
    cin >> car2 >> lis2 >> seat2;
    int q1=0,q2=0,q3=0,q4=0;
    if(car1==car2){
        q1=1;
        if(lis1==lis2){
            q2=1;
            if((seat1=='F' or seat1=='D')==(seat2=='F' or seat2=='D')){
                q3=1;
                if(abs(seat1-seat2)==1 or (seat1=='F' or seat1=='D')){
                    q4=1;
                }
            }
        }
    }
    cout << q1 << q2 << q3 << q4;
    return 0;    
}