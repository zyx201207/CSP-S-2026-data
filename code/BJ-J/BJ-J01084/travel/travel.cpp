#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string seat1,seat2,tr1,tr2;
    cin>>tr1>>seat1>>tr2>>seat2;
    if(tr1==tr2){
        cout<<"1";
        if(seat1[0] == seat2[0] && seat1[1] == seat2[1]){
            cout<<"1";
            if((seat1[2] == 'D' && seat2[2] == 'F' )|| (seat1[2] == 'F' && seat2[2] == 'D'))cout<<"11";
            else if(seat1[2] == 'D' || seat1[2] == 'F' || seat2[2] == 'D' || seat2[2] == 'F')cout<<"00";
            else{
                cout<<"1";
                if((seat1[2] == 'A' && seat2[2] == 'B')||(seat1[2] == 'B' && seat2[2] == 'A')||(seat1[2] == 'B' && seat2[2] == 'C')||(seat1[2] == 'C' && seat2[2] == 'B'))cout<<"1";
                else cout<<"0";
            }
        }
        else cout<<"000";
    }
    else{
        cout<<"0000";
    }
    return 0;
}
