#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }else{
        cout<<0;
    }
    if(b[1]==d[1]&&b[2]==d[2]){
        cout<<0;
    }else{
        cout<<1;
    }
    if(a[1]==c[1]&&b[2]==c[2]){
        cout<<0;
    }else{
        cout<<1;
    }
    if(a[1]==b[1]&&c[1]==d[1]){
        cout<<0;
    }else{
        cout<<1;
    }
    return 0;
}





