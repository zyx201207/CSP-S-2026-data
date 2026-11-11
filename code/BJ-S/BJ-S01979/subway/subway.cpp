#include<bits/stdc++.h>
using namespace std;
long long mp[505][505];
long long w[500005];
vector<long long>a[500005],t[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mp[i][j]=1e18*(i!=j);
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
            a[x].push_back(i);
            t[x].push_back(y);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<a[i].size();j++)
            for(int k=j+1;k<a[i].size();k++)
                mp[a[i][j]][a[i][k]]=mp[a[i][k]][a[i][j]]=min(mp[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        long long ans=1e18;
        for(int i=0;i<a[x].size();i++)
            for(int j=0;j<a[y].size();j++)
                ans=min(ans,w[x]+w[y]+t[x][i]+t[y][j]+mp[a[x][i]][a[y][j]]);
        cout<<ans<<"\n";
    }
    return 0;
}
