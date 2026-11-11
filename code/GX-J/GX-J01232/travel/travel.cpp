#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>b1>>a2>>b2;
    string ans="";
    if(a1==a2){
        ans+='1';
        if(b1[0]==b2[0]&&b1[1]==b2[1]){
            ans+='1';
            if(((b1[2]=='A'||b1[2]=='B'||b1[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'))){
                ans+='1';
                if((b1[2]=='A'&&b2[2]=='B')||(b1[2]=='B'&&(b2[2]=='A'||b2[2]=='C'))||(b1[2]=='C'&&b2[2]=='B'))ans+='1';
                else ans+='0';
            }
            else if((b1[2]=='D'||b1[2]=='F')&&(b1[2]=='D'||b1[2]=='F'))ans+='11';
            else ans+='00';
        }else ans+='000';

    }else ans+='0000';
    cout<<ans;
}
