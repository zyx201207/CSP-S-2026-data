#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    bool t=1;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }else{
        cout<<0;
        t=0;
    }
    if(b[0]==d[0]&&b[1]==d[1]&&t){
        cout<<1;
    }else{
        cout<<0;
        t=0;
    }
    if(t&&((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'&&b[2]!=d[2])||((b[2]=='D'||b[2]=='F')&&(d[2]=='F'&&d[2]=='D')&&b[2]!=d[2]))){
        cout<<1;
    }else{
        cout<<0;
        t=0;
    }
    if(t&&(abs((b[2]-'0')-(d[2]-'0'))==1||(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'))){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
