#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel3.in","r",stdin);
    freopen("travel3.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a[1]==c[1]){
        cout<<1;

    }
    else{
        cout<<0;
    }

    if(b[1]==d[1] && b[2]!=d[2] && a[1]==c[1]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(b[2]<'D' && d[2]<'D' && a[1]==c[1] && b[1]==d[1]){
        cout<<1;
    }

    else if(b[2]>'C' && d[2]>'C' && a[1]==c[1] && b[1]==d[1]){
        cout<<1;

    }
    else{
        cout<<0;
    }
    if(b[2],d[2]>'A' && b[2],d[2]<='C' && b[1]==d[1] && b[2]!=d[2]){
        cout<<1;
    }
    else if(b[2],d[2]<'C' && b[1]==d[1] && b[2]!=d[2]){
        cout<<1;
    }
    else if(b[2]>='D' && d[2]>='D' && b[2]!=d[2]){
        cout<<1;

    }
    else{
        cout<<0;
    }
    return 0;
}
