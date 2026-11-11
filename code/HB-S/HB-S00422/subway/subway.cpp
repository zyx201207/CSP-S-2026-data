#include<bits/stdc++.h>
using namespace std;
long long n,m,d,t,k,x,y,b[20005],ans;
bool vis[40005];
struct node
{
    long long a,b;
};
vector<node> a[40005];
map<int,long long> mp[505];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>n>>m>>d>>t;
    for(long long i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    for(long long i=1;i<=n;i++)
    {
        cin>>k;
        for(long long j=1;j<=k;j++)
        {
            cin>>x>>y;
            a[i+m].push_back({x,y});
            a[x].push_back({i+m,y});
        }
    }
    for(long long i=m+1;i<=m+n;i++)
    {
        q.push({0,i});
        while(q.size())
        {
            pair<long long,int> p=q.top();
            q.pop();
            if(p.second<=m)
            {
                if(mp[i-m][p.second]!=0)
                {
                    continue;
                }
                mp[i-m][p.second]=p.first;
            }
            else
            {
                if(mp[i-m][p.second]!=0)
                {
                    continue;
                }
                mp[i-m][p.second]=1;
            }
            for(long long j=0;j<a[p.second].size();j++)
            {
                if(mp[i-m][a[p.second][j].a]!=0)
                {
                    q.push({p.first+a[p.second][j].b,a[p.second][j].a});
                }
            }
        }
    }
    while(t--)
    {
        cin>>x>>y;
        ans=LONG_LONG_MAX;
        for(long long i=1;i<=n;i++)
        {
            ans=min(ans,1LL*mp[i][x]+mp[i][y]);
        }
        cout<<ans+b[x]+b[y]<<endl;
    }
    return 0;
}
