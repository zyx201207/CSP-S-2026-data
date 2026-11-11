#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,D,q,w[505],d[505][505005];
vector<pair<int,int> >v[505005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
void dijk(int p)
{
    d[p][p+m]=-1;
    pq.push(make_pair(0,p+m));
    while(!pq.empty())
    {
        int x=pq.top().first;
        int y=pq.top().second;
        pq.pop();
        for(int i=0;i<v[y].size();i++)
        {
            if(d[p][v[y][i].first]==0)
            {
                d[p][v[y][i].first]=x+v[y][i].second;
                pq.push(make_pair(d[p][v[y][i].first],v[y][i].first));
            }
        }
    }
    d[p][p+m]=0;
    return;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>D>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=1;j<=x;j++)
        {
            int y,z;
            cin>>y>>z;
            v[m+i].push_back(make_pair(y,z));
            v[y].push_back(make_pair(m+i,z));
        }
    }
    for(int i=1;i<=n;i++)
    {
        dijk(i);
    }
    for(int i=1;i<=q;i++)
    {
        int x,y,ans=0x3f3f3f3f3f3f3f3f;
        cin>>x>>y;
        for(int j=0;j<v[x].size();j++)
        {
            for(int k=0;k<v[y].size();k++)
            {
                ans=min(ans,w[x]+w[y]+d[v[x][j].first-m][v[y][k].first]+v[x][j].second+v[y][k].second);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
i want to up bj s team "do joy";
*/
