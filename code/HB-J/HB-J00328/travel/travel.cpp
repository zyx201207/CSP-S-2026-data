#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]) cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    int m,n;
    if(b[2]=='A'||b[2]=='B'||b[2]=='C') m=0;
    else m=1;
    if(d[2]=='A'||d[2]=='B'||d[2]=='C') n=0;
    else n=1;
    if(m==n) cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if(abs(b[2]-'0'-(d[2]-'0'))==1) cout<<"1";
    else if(b[2]=='D'||b[2]=='F') cout<<"1";
    else cout<<"0";
    return 0;
}
