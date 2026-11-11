#include <bits/stdc++.h>
using namespace std;
int a[100000];
string ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,cc,ss;
    char num1=s[0]+s[1];
    char num2=ss[0]+ss[1];
    cin>>c>>s>>cc>>ss;
    if(c==cc){
        ans+="1";
    }
    else{
        ans+="0";
    }
    if(c==cc&&s[0]==ss[0]&&s[1]==ss[1]){
        ans+="1";
    }
    else{
        ans+="0";
    }
    char s1=s[2],s2=ss[2];
    if(((s1<=67&&s2<=67)||(s1>67&&s2>67))&&num1==num2){
        ans+="1";
    }
    else{
        ans+="0";
    }
    char xl1=s[2]+1,xl2=s[2],xl3=ss[2]+1,xl4=ss[2];
    if(xl1==68||xl2==67||xl3==68||xl4==67){
        ans+="0";
    }
    else if((xl1==xl4||xl2==xl3)&&num1==num2){
        ans+="1";
    }
    else{
        ans+="0";
    }
    cout<<ans;
    return 0;
}

