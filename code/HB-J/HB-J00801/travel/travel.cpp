#include<bits/stdc++.h>
using namespace std;
string a[5],b[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=2;i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    int x=1;
    if(a[1]!=a[2]&&a[1]!="06"&&a[1]!="17") x=0;
    if(x==1) cout<<1;
    else {cout<<"0000";return 0;}
    int t=1;
    for(int i=0;i<2;i++)
    {
        if(b[1][i]!=b[2][i]) t=0;
    }
    if(t==1&&x==1) cout<<1;
    else {cout<<"000";return 0;}
    int m=1;
    if(b[1][2]<='C'&&b[2][2]>='D'||b[1][2]>='D'&&b[2][2]<='C') m=0;
    if(x==1&&t==1&&m==1) cout<<1;
    else {cout<<"00";return 0;}
    int n=1;
    if(b[1][2]<='C'&&(abs(b[1][2]-b[2][2])!=1)) n=0;
    if(x==1&&t==1&&m==1&&n==1) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}