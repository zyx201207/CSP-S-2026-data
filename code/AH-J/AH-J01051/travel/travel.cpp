#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define ffor(i,a,b) for(ll i=(a);i<=(b);++i)
#define roff(i,a,b) for(ll i=(a);i>=(b);--i)
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<"0000";
    }else if(a2[0]!=b2[0]||a2[1]!=b2[1]){
        cout<<"1000";
    }else{
        cout<<"11";
        ll t1,t2;
        if(a2[2]=='A') t1=1;
        if(a2[2]=='B') t1=2;
        if(a2[2]=='C') t1=3;
        if(a2[2]=='D') t1=4;
        if(a2[2]=='E') t1=5;
        
        if(b2[2]=='A') t2=1;
        if(b2[2]=='B') t2=2;
        if(b2[2]=='C') t2=3;
        if(b2[2]=='D') t2=4;
        if(b2[2]=='E') t2=5;
        if(t1<=3&&t2<=3||t1>3&&t2>3){
            ll t=t2-t1;
            if(t==-1||t==1) cout<<"11";
            else cout<<"10";
        }else{
            cout<<"00";
        }
    }
    return 0;
}