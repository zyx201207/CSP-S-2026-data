#include<bits/stdc++.h>
using namespace std;
int xiang1,xiang2;
string seat1,seat2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>xiang1>>seat1>>xiang2>>seat2;
    if(xiang1==xiang2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]){
        cout<<1;
    }else {
        cout<<"000";return 0;
    }
    if(seat1[2]=='A'||seat1[2]=='B'||seat1[2]=='C'&&seat2[2]=='A'||seat2[2]=='B'||seat2[2]=='C'){
        cout<<1;
    }else if(seat1[2]=='D'||seat1[2]=='F'&&seat2[2]=='D'||seat2[2]=='F'){
        cout<<1;
    }else{
        cout<<"00";return 0;
    }
    if(seat1[2]-seat2[2]==1&&seat1[2]!='D'){
        cout<<1;
    }
    else if(seat2[2]-seat1[2]==1&&seat1[2]!='C'){
        cout<<1;
    }else if(seat1[2]=='D'&&seat2[2]=='F'){
        cout<<1;
    }else if(seat1[2]=='F'&&seat2[2]=='D'){
        cout<<1;
    }else cout<<0;

}
