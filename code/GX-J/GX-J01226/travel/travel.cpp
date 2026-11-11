#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,ans="";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out", "w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans+='1';
    }
    else {
        ans+='0';
        ans+='0';
        ans+='0';
        ans+='0';
        cout<<ans;
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        ans+='1';
    }
    else {
        ans+='0';
        ans+='0';
        ans+='0';
        cout<<ans;
        return 0;
    }
    if(s1[2]=='C'&&s2[2]=='D'){
            ans+='0';
            ans+='0';
    }
    else {
        ans+='1';
        if(s1[2]=='B'||s2[2]=='B'){
        ans+='1';
      }
        else ans+='0';
    }
    cout<<ans;
    return 0;
}
