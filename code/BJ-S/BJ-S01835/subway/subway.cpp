#include<bits/stdc++.h>
using namespace std;
int div[50005],a[505][505],t[505][505],k[505],w1[505];
vector<pair<int,int>> g[50005];
void d(int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=1; i<=505; i++)
    {
        div[i]=0;
    }
    div[s]=0;
    pq.push({div[s],s});
    while(!pq.empty())
    {
        int u=pq.top().second();
        pq.pop();
        for(auto[v,w] : g[u])
        {
            if(div[v]>div[u]+w)
            {
                div[v]=div[u]+w;
                pq.push(div[v],v);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++)
    {
        cin>>w1[i];
    }
    for(int i=1; i<=n; i++)
    {

        cin>>k[i];
        for(int j=1; j<=k[i]; i++)
        {
            cin>>a[i][j]>>t[i][j];
            if(j>=2)
            {
                g[a[i][j]].push_back({a[i][j-1],0});
                g[a[i][j-1]].push_back({a[i][j],0});
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int w=1; w<=k[i]; w++)
            for(int d=i+1; d<=n; d++)
                for(int j=1; j<=k[d]; j++)
                {
                    if(a[i][w]==a[d][j]){g[a[i][w]].push_back({a[d][j],t[i][w]+t[d][j]}); g[a[d][j]].push_back({a[i][w],t[i][w]+t[d][j]});}
                }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        d(x);
        cout<<div[y]+w1[x]+w1[y]<<endl;
    }
    return 0;
}
