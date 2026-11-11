#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2;
int s1,s2;
char ss1,ss2;
string ans;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>c1>>s1>>ss1>>c2>>s2>>ss2;
    if(c1==c2){
        ans+="1";
        if(s1==s2){
            ans+="1";
            if('C'>=ss1&&'C'>=ss2||'D'<=ss1&&'D'<=ss2){
                ans+="1";
                int delta=abs(ss1-ss2);
                if(delta==1||ss1>='D'&&ss2>='D'){
                    ans+="1";
                }else ans+="0";
            }else ans+="00";
        }else{
            ans+="000";
        }
    }
    else ans+="0000";
    cout<<ans;
    return 0;
}
