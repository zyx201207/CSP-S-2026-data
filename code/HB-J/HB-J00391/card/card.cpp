#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,m,a[N],ans[N],lst[N],cnt[N];

signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i],cnt[i]=1;
    for (int i=n;i>=1;i--)
        if (!lst[a[i]]) lst[a[i]]=i;
    for (int i=1;i<=n;i++)
    {
        if (lst[a[i]]==i)
        {
            ans[a[i]]+=cnt[i];
            cnt[i+1]+=cnt[i];
        }
        else cnt[lst[a[i]]]+=cnt[i];
    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
