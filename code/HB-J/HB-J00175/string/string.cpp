#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        char c;
        cin>>c;
        for(int i=1;i<=a;i++)s.push_back(c);
    }
    int ans=0;
    for(int i=0;i<s.length()/2;i++)
        ans+=(s[i]!=s[s.length()-i-1]);
    cout<<ans<<'\n';
    return 0;
}