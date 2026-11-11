#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
struct N{
    char c;
    int x;
}a[200005];
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
        for(int j=1;j<=a[i].x;j++)s+=a[i].c;
    }
    for(int i=0;i<=s.size()-i-1;i++){
        if(s[i]!=s[s.size()-1-i])ans++;
    }
    cout<<ans;
    return 0;
}
