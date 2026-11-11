#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define un unsigned
int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数
int w[500005],k[505];
vector<pair<int,int> > lsearch[500005];
vector<pair<int,ll> > line[505];
//d
ll dist[500005];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;//t,n
ll solve(int x,int y)
{
    for(int i=0;i<m;i++) dist[i]=10000000000000000;
    dist[x]=0;
    pq.push(make_pair(0,x));
    while(!pq.empty())
    {
        int node=pq.top().second;
        int time=pq.top().first;
        pq.pop();
        if(time!=dist[node]) continue;
        for(un int i=0;i<lsearch[node].size();i++)
        {
            int nline=lsearch[node][i].first,nindex=lsearch[node][i].second;
            for(un int j=0;j<line[nline].size();j++)
            {
                if(j==un(nindex)) continue;
                if(dist[line[nline][j].first]> time+line[nline][nindex].second+line[nline][j].second)
                {
					dist[line[nline][j].first]=time+line[nline][nindex].second+line[nline][j].second;
                    pq.push(make_pair(time+line[nline][nindex].second+line[nline][j].second,line[nline][j].first));
                }
            }
        }
    }
    return dist[y];

}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++) cin>>w[i];
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
        for(int j=0;j<k[i];j++)
        {
            int node;
            ll t;
            cin>>node>>t;
            lsearch[node].push_back(make_pair(i,j));
            line[i].push_back(make_pair(node,t));
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<solve(x,y)+1LL*w[x-1]+1LL*w[y-1]<<endl;
    }
}
