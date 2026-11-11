#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a[1]==c[1]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a[1]==c[1]&&b[1]==d[1]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a[1]!=c[1]){
        cout<<0;
    }
    else{
        cout<<1;
    }
    if(a[0]!=c[0]){
        cout<<0;
    }
    else{
        cout<<1;
    }
    return 0;
}
