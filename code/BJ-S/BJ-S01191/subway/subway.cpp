#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
struct node
{
    int to,h;
};
const int N=500010;
int c,n,m,d,Q;
int w[500010],a,t;
bool vis[500010];
vector<node>V[501000];
queue<int>query[500010],que;
int dis[501000],ans[101000];
int x[100010],y[100010];
queue<node>q;
map<pair<int,int>,int>mp;
void dij(int x)
{
    memset(dis,0x3f,sizeof(dis));
    q.push({x,0});
    dis[x]=0;
    while(!q.empty())
    {
        node cur=q.front();
        q.pop();
        int nxt=cur.to,len=cur.h;
        for(auto v:V[nxt])
        {
            if(dis[v.to]>len+v.h)
            {
                dis[v.to]=len+v.h;
                q.push({v.to,dis[v.to]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int k;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>t;
            V[a].push_back({i+N,t});
            V[i+N].push_back({a,t});
        }
    }
    dij(1);
    for(int i=1;i<=Q;i++)
    {
        cin>>x[i]>>y[i];
        if(x[i]>y[i]) swap(x[i],y[i]);
        query[x[i]].push(y[i]);
        ans[i]=w[x[i]]+w[y[i]];
        if(!vis[x[i]])
        {
            que.push(x[i]);
            vis[x[i]];
        }
    }
    while(!que.empty())
    {
        int tmp=que.front();
        que.pop();
        dij(tmp);
        int tmp2;
        while(!query[tmp].empty())
        {
            tmp2=query[tmp].front();
            mp[make_pair(tmp,tmp2)]=dis[tmp2];
            query[tmp].pop();
        }
    }
    for(int i=1;i<=Q;i++)
    {
        cout<<mp[make_pair(x[i],y[i])]+ans[i]<<endl;
    }
    return 0;
}
