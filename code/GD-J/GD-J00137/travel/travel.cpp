#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,cc,ss;
    cin>>c>>s>>cc>>ss;
    string res="";
    if(c==cc){
        res+='1';
    }else{
        res+='0';
    }
    if(c==cc&&s[1]==ss[1]){
        res+='1';
    }else{
        res+='0';
    }
    if(c==cc&&s[1]==ss[1]&&((s[2]>='A'&&s[2]<='C'&&ss[2]>='A'&&ss[2]<='C')||((s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D')))){
        res+='1';
    }else{
        res+='0';
    }
    if(c==cc&&s[1]==ss[1]&&((s[2]=='A'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='A')||(s[2]=='B'&&ss[2]=='C')||(s[2]=='C'&&ss[2]=='B')||(s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D'))){
        res+='1';
    }else{
        res+='0';
    }
    cout<<res;
    return 0;
}