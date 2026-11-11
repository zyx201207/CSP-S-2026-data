#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r1,r2,x1,x2;
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    int r=r2[0]*10-480+r2[1]-48,x=x2[0]*10-480+x2[1]-48;
    if(r==x)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    int b=r2[2],s=x2[2];
    if(b<s)swap(b,s);
    if(b>='D'&&s<='C'){
        cout<<"00";
        return 0;
    }
    else{
        cout<<1<<(((b-s==1&&b!=68)||(b==70&&s==68))?1:0);
    }
    return 0;
}