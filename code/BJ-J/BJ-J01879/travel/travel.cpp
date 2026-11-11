#include<bits/stdc++.h>
using namespace std;
#define LL long long
string c1,s1,c2,s2,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ans="0000";
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans[0]='1';
        if(s1.substr(0,2)==s2.substr(0,2)){
            ans[1]='1';
            if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
                ans[2]='1';
                if(abs(s1[2]-s2[2])==1) ans[3]='1';
            }
            if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
                ans[2]='1';
                ans[3]='1';
            }
        }

    }cout<<ans;
    return 0;
}
