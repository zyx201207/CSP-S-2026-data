#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5+5;
long long n,m,a[maxn],lst[maxn],t[maxn],ans[maxn],cnt[maxn];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        cnt[i]=1;
        if(!lst[a[i]])lst[a[i]]=i;
        t[i]=lst[a[i]]+1;
    }
    for(int i=1;i<=n;i++)
    {
        ans[a[i]]+=cnt[i];
        cnt[t[i]]+=cnt[i];
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}