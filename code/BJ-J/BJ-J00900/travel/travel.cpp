#include<bits/stdc++.h>
using namespace std;
void is(string a,string b,string c,string d){
    if(a[1]==c[1]&&a[0]==c[0]){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return;
    }
    if(b[0]==d[0]&&b[1]==d[1]){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        return;
    }
    if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(a[2]=='A'||a[2]=='B'||a[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(a[2]=='D'||a[2]=='F'))){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        return;
    }
    if((b[2]=='A'&&d[2]=='B')||(d[2]=='A'&&b[2]=='B')||(b[2]=='B'&&d[2]=='C')||(d[2]=='B'&&b[2]=='C')||(b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F')){
        cout<<1;
    }
    else{
        cout<<0;
        return;
    }
    return;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    is(a,b,c,d);
    return 0;
}