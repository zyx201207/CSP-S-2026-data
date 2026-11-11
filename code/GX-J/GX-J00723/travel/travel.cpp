#include<bits/stdc++.h>
using namespace std;
string a;
string b;
string c;
string d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)cout<<1;
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(b[0]+b[1]==d[0]+d[1]) cout<<1;
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if((b[2]<='F'&&b[2]>='D'&&d[2]<='F'&&d[2]>='D')||(b[2]<='C'&&b[2]>='A'&&d[2]<='C'&&d[2]>='A')) cout<<1;
    else{
        cout<<0;
        cout<<0;
        return 0;
    }
    if(b[2]+1==d[2]||b[2]-1==d[2])cout<<1;
    else cout<<0;
}
