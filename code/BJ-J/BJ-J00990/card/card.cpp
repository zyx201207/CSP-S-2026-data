#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10,M=3e5+10;
int n,m,a[N],ans[M],cnt[M],id[M],v[N];

signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(i!=1&&a[i]<a[i-1]) flag=0;
    }
    if(flag)
    {
        for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],i);
        for(int i=1;i<=m;i++) cout << ans[i] << " ";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=m;j++) cnt[j]=id[j]=0;
        for(int j=1;j<=n;j++) cnt[j]=0;
        int len=0;
        for(int j=i;j<=n;j++)
        {
            if(cnt[a[j]])
            {
                for(int k=id[a[j]]+1;k<=len;k++)
                {
                    cnt[v[k]]=0;
                    id[v[k]]=0;
                }
                len=id[a[j]];
            }
            else
            {
                v[++len]=a[j];
                cnt[a[j]]=1;
                id[a[j]]=len;
            }
        }
        for(int j=1;j<=len;j++) ans[v[j]]++;
    }
    for(int i=1;i<=m;i++) cout << ans[i] << " ";
    return 0;
}
