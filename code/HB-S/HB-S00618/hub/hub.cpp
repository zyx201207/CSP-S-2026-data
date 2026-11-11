#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,f[2000005],ans,a[2000005],b[2000005],cnt,d[2000005],e[2000005],cnt1,cnt2,maxn,g[2000005],h[2000005],cnt3;
vector<int> v[2000005];
void dfs(int x)
{
    for(int i = 0;i<(int)v[x].size();i++)
    {
        if(v[x][i]!=f[x])
        {
            f[v[x][i]] = x;
            dfs(v[x][i]);
        }
    }
}
void dfs1(int x,int y)
{
    for(int i = 0;i<(int)v[x].size();i++)
    {
        if(v[x][i]!=f[x])
        {
            dfs1(v[x][i],y);
            b[x] = min(b[x],b[v[x][i]]+1);
            a[x] = max(a[x],a[v[x][i]]+1);
            if(d[v[x][i]]==1||e[x]!=0)
            {
                e[x]++;
            }
        }
    }
    if(v[x].size()==0)
    {
        b[x] = -1e18;
        a[x] = 0;
    }
    if(a[x]+b[x]<=y&&b[x]>=0)
    {
        a[x] = min(b[x],a[x]);
    }
    else if(a[x]>=y)
    {
        cnt++;
        a[x] = 0;
        b[x] = 0;
        d[x] = 1;
    }
}
void dfs2(int x)
{
    h[x] = h[f[x]];
    if(d[x]==1)
    {
        h[x]++;
    }
    for(int i = 0;i<(int)v[x].size();i++)
    {
        if(v[x][i]!=f[x])
        {
            dfs2(v[x][i]);
            if(h[x]!=0&&e[x]>=1&&e[x]<3&&d[x]==0)
            {
                cnt1++;
                g[x] = 1;
                if(g[f[x]]!=1)
                {
                    cnt2 = 0;
                }
                cnt2++;
                maxn = max(maxn,cnt2);
            }
        }
    }
    if(e[x]>=3)
    {
        cnt++;
    }
    if(h[x]==0&&e[x]>=1)
    {
        cnt2++;
    }
}
bool check(int x)
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(e,0,sizeof(e));
    memset(g,0,sizeof(g));
    memset(h,0,sizeof(h));
    cnt = 0;
    dfs1(1,x);
    cnt1 = 0;
    cnt2 = 0;
    maxn = 0;
    cnt3 = 0;
    dfs2(1);
    maxn = max(maxn,cnt3);
    printf("%lld %lld\n",x,cnt);
    cnt = cnt+cnt1-cnt3;
    if(cnt>k)
    {
        return false;
    }
    return true;
}
signed main()
{
//  freopen("hub.in","r",stdin);
//  freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for(int i = 1;i<=t;i++)
    {
        scanf("%lld%lld",&n,&k);
        for(int j = 1;j<=n;j++)
        {
            v[j].clear();
            f[j] = 0;
        }
        for(int j = 1,x,y;j<n;j++)
        {
            scanf("%lld%lld",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1);
        int l = 1,r = n;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(check(mid))
            {
                r = mid-1;
                ans = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
