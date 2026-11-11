#include <bits/stdc++.h>
using namespace std;
long long a[200005],maxn=-1;
int n,m;
void dfs(int p,long long sum,int cnt)
{
    if(p==n+1)
    {
        if(cnt==m)
            maxn=max(maxn,sum);
        return ;
    }
    if(cnt==m)
    {
        maxn=max(maxn,sum);
        return ;
    }
    dfs(p+1,sum,cnt);
    if(cnt==0)
        dfs(p+1,a[p],cnt+1);
    else
        dfs(p+1,(sum & a[p]),cnt+1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    dfs(1,0,0);
    cout << maxn;
    return 0;
}
