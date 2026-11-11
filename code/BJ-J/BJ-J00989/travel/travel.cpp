#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;

    cin>>a>>b>>c>>d;
    char x=b[2],y=d[2];
    if(a==c){
        cout<<1;
    }else{
        cout<<0;
    }
    if(b[0]==d[0]&&b[1]==d[1]&&a==c){
        cout<<1;
    }else{
        cout<<0;
    }
    if(b[0]==d[0]&&b[1]==d[1]&&a==c&&(((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C'))||((x=='D'||x=='F')&&(y=='D'||y=='F')))){
        cout<<1;
    }else{
        cout<<0;
    }
    if(b[0]==d[0]&&b[1]==d[1]&&a==c&&(min(x,y)+1==max(x,y))&&(((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C'))||((x=='D'||x=='F')&&(y=='D'||y=='F')))){
        cout<<1;
    }else{
        cout<<0;
    }

    return 0;
}
