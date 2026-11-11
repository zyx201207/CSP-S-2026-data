#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005,MAXM=300005;
int n,m,a[MAXN],t[MAXM],p[MAXN],f[MAXM],ans[MAXM];
bool v[MAXN];
int dfs(int x)
{
    int d=1-f[a[x]],c=1;
    f[a[x]]+=d;
    if(p[x])c+=dfs(p[x]);
    if(x!=1&&!v[x-1])c+=dfs(x-1);
    f[a[x]]-=d,ans[a[x]]+=d*c;
    return c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],p[i]=t[a[i]],v[t[a[i]]]=1,t[a[i]]=i;
    dfs(n);
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}