#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],dist[505][505];
vector<pair<long long,int>> point[500005];
vector<pair<long long,int>> to[505];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x;
            long long num;
            cin>>x>>num;
            point[x].push_back({num,i});
        }
    }
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=m;i++)
    {
        if(point[i].size()>1)
        {
            for(int j=0;j<point[i].size();j++)
            {
                for(int k=0;k<point[i].size();k++)
                {
                    if(k==j) continue;
                    to[point[i][j].second].push_back({point[i][j].first+point[i][k].first,point[i][k].second});
                    to[point[i][k].second].push_back({point[i][j].first+point[i][k].first,point[i][j].second});
                    dist[point[i][j].second][point[i][k].second]=point[i][j].first+point[i][k].first;
                    dist[point[i][k].second][point[i][j].second]=point[i][j].first+point[i][k].first;
                }
            }
        }
    }
    //for(int i=1;i<=m;i++)
    //{
     //   for(int j=0;j<to[i].size();i++) cout<<to[i][j].first<<" "<<to[i][j].second<<endl;
     //   cout<<endl;
    //}
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) dist[i][j]=0;
                dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cout<<dist[i][j]<<" ";
        cout<<endl;
    }*/
    /*for(int i=1;i<=m;i++)
    {
        cout<<i<<":";
        for(int j=0;j<point[i].size();j++) cout<<point[i][j].second<<" "<<point[i][j].first<<endl;;
        cout<<endl;
    }*/
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        long long ans=1e18;
        for(int i=0;i<point[x].size();i++)
        {
            for(int j=0;j<point[y].size();j++)
            {
                if(point[x][i].second==point[y][j].second)
                {
                    ans=min(ans,point[x][i].first+point[y][j].first);
                }
                ans=min(ans,dist[point[x][i].second][point[y][j].second]+point[x][i].first+point[y][j].first);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
