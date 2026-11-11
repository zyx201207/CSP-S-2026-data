#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2,ans;
map<char,int>mp;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    mp['A']=1,mp['B']=2,mp['C']=3,mp['D']=4,mp['F']=5;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)ans.push_back('1');
    else ans.push_back('0');
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&ans[0]=='1')ans.push_back('1');
    else ans.push_back('0');
    if(((mp[s1[2]]<=3&&mp[s2[2]]<=3)||(mp[s1[2]]>=4&&mp[s2[2]]>=4))&&ans[1]=='1')ans.push_back('1');
    else ans.push_back('0');
    if(ans[2]=='1'&&(int)abs(mp[s1[2]]-mp[s2[2]])==1)ans.push_back('1');
    else ans.push_back('0');
    cout<<ans;
    return 0;
}