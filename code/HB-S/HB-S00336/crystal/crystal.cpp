#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans;
int a[N],s[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int last=1;
    for(int i=1;i<=n;i++){
        while(a[i]*(i-last+1)-(s[i]-s[last-1])>m) last++;
        ans=max(ans,i-last+1);
    } cout<<ans<<'\n';
    return 0;
}