#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int c,n,m,d,q,gms;
int w[N],a[500][N],t[500][N];
vector<int> mp[3*N];
map<int,map<int,int>> dis;
inline void sol1()
{
    int vis[3*N];
    memset(vis,127,sizeof vis);
    int x,y;
    cin>>x>>y;
    //q.first->id q.second->distance
    priority_queue <pair<int,int>> q;
    q.push({x,0});
    while(!q.empty())
    {
        pair<int,int> p=q.top();
        //cerr<<p.first<<" "<<p.second<<"\n";
        q.pop();
        if(vis[p.first]<=p.second)
        {
            continue;
        }
        else
        {
            vis[p.first]=p.second;
        }
        if(p.first!=y)
        {
            for(auto i:mp[p.first])
            {
                q.push({i,p.second+dis[i][p.first]});
            }
        }
    }
    cout<<vis[y]<<"\n";
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
        mp[i].push_back(N+i);
        mp[N+i].push_back(i);
        dis[i][N+i]=w[i];
        dis[N+i][i]=w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][j]>>t[i][j];
            gms++;
            mp[N+a[i][j]].push_back(2*N+gms);
            mp[2*N+gms].push_back(N+a[i][j]);
            dis[N+a[i][j]][2*N+gms]=t[i][j];
            dis[2*N+gms][N+a[i][j]]=t[i][j];
            if(j!=1)
            {
                mp[2*N+gms].push_back(2*N+gms-1);
                mp[2*N+gms-1].push_back(2*N+gms);
                dis[2*N+gms-1][2*N+gms]=0;
                dis[2*N+gms][2*N+gms-1]=0;
            }
        }

    }
    //cerr<<"step1-ok\n";
    for(int i=1;i<=q;i++)
    {
        sol1();
    }
}
//diff subway.out subway.ans
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
