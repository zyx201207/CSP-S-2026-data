#include<bits/stdc++.h>
using namespace std;
string s,t,c,d;
string ans;
bool x,y,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>c>>t>>d;
    if(s==t) {ans=ans+'1'; x=1;}
    else ans=ans+'0';
    if(c[0]==d[0]&&c[1]==d[1]&&x) {ans+='1'; y=1;}
    else ans+='0';
if(y){
    if((c[2]=='A'||c[2]=='B'||c[2]=='C')){
        if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
            ans+='1';
            b=1;
        }
        else ans+='0';
    }
    else{
        if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
            ans+='0';
        }
        else {ans+='1'; b=1;}
    }
}
else ans+='0';
if(b){
    if(c[2]+1==d[2]||c[2]-1==d[2]){
        if(c[2]=='C'&&d[2]=='D'){
            ans+='0';
        }
        else if(c[2]=='D'&&d[2]=='C'){
            ans+='0';
        }
        else{
            ans+='1';
        }
    }
    else ans+='0';
}
else ans+='0';
    cout<<ans;
    return 0;
}
