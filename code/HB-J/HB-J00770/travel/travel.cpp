#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;//b is set
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    if(a1==a2)cout<<1;
    else {cout<<"0000";return 0;}

    int t1=(b1[0]-'0')*10+b1[1]-'0',t2=(b2[0]-'0')*10+b2[1]-'0';
    if(t1==t2)cout<<1;
    else {cout<<"000";return 0;}

    t1=b1[2]-'A';
    t2=b2[2]-'A';

    if(t1>t2)swap(t1,t2);
    if(0<=t1&&t1<=2&&0<=t2&&t2<=2)cout<<1;
    else if(3<=t1&&t1<=4&&3<=t2&&t2<=4)cout<<1;
    else {cout<<"00";return 0;}
    if(t1+1==t2||t2+1==t1)cout<<1;
    else cout<<"0";
    return 0;
}
