#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,st[500005],w[500005],nw[500005];
struct node{
    long long to,lnh;
};
vector<node> mp[11000000];
long long dfs(int u,int v,long long w,int fa)
{
    if(u==v) return w;
    long long minn=1e18;
    for(int i=0;i<mp[u].size();i++)
    {
        if(fa==mp[u][i].to) continue;
        minn=min(minn,dfs(mp[u][i].to,v,mp[u][i].lnh+w,u));
    }
    return minn;
}
int main()
{
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
        nw[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        long long ki,a[500005],t[500005];
        cin >> ki;
        for(int j=1;j<=ki;j++)
        {
            cin >> a[j] >> t[j];
            mp[(a[j]-1)*(d+1)+1].push_back({(a[j]-1)*(d+1)+nw[a[j]]+1,t[j]});
            mp[(a[j]-1)*(d+1)+nw[a[j]]+1].push_back({(a[j]-1)*(d+1)+1,t[j]});
            nw[a[j]]++;
            if(j!=1)
            {
                mp[(a[j]-1)*(d+1)+nw[a[j]]+1].push_back({(a[j-1]-1)*(d+1)+nw[a[j-1]]+1,0});
                mp[(a[j-1]-1)*(d+1)+nw[a[j-1]]+1].push_back({(a[j]-1)*(d+1)+nw[a[j]]+1,0});
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        long long x,y;
        cin >> x >> y;
        x=(x-1)*(d+1)+1;
        y=(y-1)*(d+1)+1;
        cout << dfs(x,y,0,0) << endl;
    }
    return 0;
}
