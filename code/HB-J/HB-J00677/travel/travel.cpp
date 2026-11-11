#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2,ans="0000";
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans[0]='1';
    }
    else{
        cout<<ans;
        return 0;
    }
    if(s1[1]==s2[1]&&s1[0]==s2[0]){
        ans[1]='1';
    }
    else{
        cout<<ans;
        return 0;
    }
    if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
        ans[2]='1';
    }
    else{
        cout<<ans;
        return 0;
    }
    if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
        ans[3]='1';
    }
    cout<<ans;
    return 0;
}
