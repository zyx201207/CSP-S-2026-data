#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,h,l;
    cin>>a>>h;

    cin>>b>>l;
    if(a[1]==b[1])cout<<1;
    else cout<<0;
    if(a==b&&h[0]==l[0]&&h[1]==l[1])cout<<1;
    else cout<<0;
    int u=0,n=0,uu,nn;
    if(h[2]-64<4)u=1;
    if(l[2]-64<4)n=1;
    if(a==b&&h[0]==l[0]&&h[1]==l[1]&&u==n)cout<<1;
    else cout<<0;
    uu=h[2]-64;
    nn=l[2]-64;
    if(a==b&&h[0]==l[0]&&h[1]==l[1]&&u==n&&n==0)cout<<1;
    else if(a==b&&h[0]==l[0]&&h[1]==l[1]&&u==n&&!(max(uu,nn)==3&&min(uu,nn)==1))cout<<1;
    else cout<<0;
    return 0;
}
