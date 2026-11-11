#include<bits/stdc++.h>
#define int long long
string carr,seatr,carx,seatx;
bool flag=0,flag1=0;
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>carr>>seatr>>carx>>seatx;
    if(carr==carx)  {
        cout<<"1";
        flag==1;
    }else{
        cout<<"0";
    }
    if(flag&&seatr[0]+seatr[1]==seatx[0]+seatx[1]){
        cout<<"1";
        flag1=0;
    }else{
        cout<<"0";
   }
    if(flag1){
        if(seatr[2]=='A'||seatr[2]=='B'||seatr[2]=='C'){
            if(seatx[2]=='B')   cout<<"1";
            else if(seatx[2]=='C')  cout<<"1"
            else if(seatx[2]=='A')cout<<"1";
        }else if(seatr[2]=='D'||seatr[2]=='F'){
            if(seatx[2]=='D')   cout<<"1";
            else if(seatx[2]=='F')  cout<<"1";
        }else   cout<<"0";
    }else{
        cout<<"0";
    }
    if(flag&&flag){
    if(seatr[2]=='A'&&seatx[2]=='B')    cout<<"1";
    else if(seatr[2]=='B'&&(seatx[2]=='A'||seatx[2]=='C')   cout<<"1";
    else if(seatr[2]=='C'&&seatx[2]=='B')   cout<<"1";
    else if(seatr[2]=='D'&&seatx[2]=='F')   cout<<"1";
    else if(seatr[2]=='F'&&seatx[2]=='D')   `cout<<"1";
    else<<"0";
    }
    return 0;
}