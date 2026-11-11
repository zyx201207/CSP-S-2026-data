#include<bits/stdc++.h>
using namespace std;
int x,y,a,b,c,d,n=0;
string s;
string syx;
int main(){
   freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x;
    cin>>s;
    cin>>y;
    cin>>syx;
    if(x!=y){
        cout<<0<<0<<0<<0;
        return 0;
    }
    cout<<1;
    c=(s[0]-48)*10+(s[1]-48);
    d=(syx[0]-48)*10+(syx[1]-48);
    if(syx[0]==s[0]&&s[1]==syx[1]){
        cout<<1;
        n=1;
    }
    else{
        cout<<0;
    }
    if(syx[2]=='F'||syx[2]=='D'){
        a=1;
    }
    else{
        a=0;
    }
    if(s[2]=='F'||s[2]=='D'){
        b=1;
    }
    else{
        b=0;
    }
    if(a==b&&n==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(n==1&&b==a){
        c=s[2]-48;
        d=syx[2]-48;
        if(c+1==d||c-1==d){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }



    return 0;
}
