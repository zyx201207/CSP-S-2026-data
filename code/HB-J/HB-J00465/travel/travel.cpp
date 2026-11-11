#include<bits/stdc++.h>
using namespace std;
string ca,cb,ra,rb;
int f=0,fl=0,fla=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ca>>ra>>cb>>rb;
    if(ca==cb){
        cout<<1;
        f=1;
    }
    else{
        cout<<0;
    }
    if(int(ra[0]*10+ra[1])==int(rb[0]*10+rb[1]) && f){
        cout<<1;
        fl=1;
    }
    else{
        cout<<0;
    }
    if((((ra[2]=='A' || ra[2]=='B' || ra[2]=='C') && (rb[2]=='A' || rb[2]=='B' || rb[2]=='C')) || ((ra[2]=='D' || ra[2]=='F') && (rb[2]=='D' || rb[2]=='F'))) && fl){
        cout<<1;
        fla=1;
    }
    else{
        cout<<0;
    }
    if((((ra[2]=='A' || ra[2]=='B') && (rb[2]=='A' || rb[2]=='B')) || ((ra[2]=='D' || ra[2]=='F') && (rb[2]=='D' || rb[2]=='F')) || ((ra[2]=='B' || ra[2]=='C') && (rb[2]=='B' || rb[2]=='C'))) && fla){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
