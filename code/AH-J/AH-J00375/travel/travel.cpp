#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    string e=b.substr(0,2),f=d.substr(0,2);
    if(e==f){
        cout<<1;
    }else{
        cout<<0<<0<<0;
        return 0;
    }
    if(b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||b[2]=='B'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='C'&&d[2]=='A'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
        cout<<1;
    }else{
        cout<<0<<0;
        return 0;
    }
    if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='F'&&d[2]=='D'){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
