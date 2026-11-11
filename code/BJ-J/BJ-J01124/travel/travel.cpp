#include<bits/stdc++.h>
using namespace std;
#define int long long

string c1,s1,c2,s2;
int ans,ans2,ans3,ans4;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0] && c1[1]==c2[1]){
        ans=1;
        if(s1[0]==s2[0] && s2[1]==s1[1]){
            ans2=1;
            if(((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')) || ((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D'))){
                ans3=1;
                if((!((s1[2]=='C' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='C'))) && (s1[2]-s2[2]==1 || s2[2]-s1[2]==1)) ans4=1;
            }
        }
    }
    cout<<ans<<ans2<<ans3<<ans4;
    return 0;
}
