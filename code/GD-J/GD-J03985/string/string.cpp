#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++)s.push_back(c);
    }
    int ans=0;
    for(int i=(int)(s.size()+1)/2;i<(int)s.size();i++){
        if(s[i]!=s[(int)(s.size())-i-1])ans++;
    }
    cout<<ans<<"\n";
    return 0;
}