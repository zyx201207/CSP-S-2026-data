
#include<bits/stdc++.h>
#define PII pair<int,int>
#define Fi first
#define Se second
using namespace std;
const int N=2e5+10;
int c,n,m,d,q,w[N],a[510][N],t[510][N];
struct Node
{
    int x,y,id;
    bool operator<(const Node&oth)const
    {
        return x<oth.x;
    }
}ask[N];
vector<PII> edge[N];
void subtaskA()
{
    int vis[N],ans[N],dis[N];
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
        if(k<2) continue;
        edge[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
        edge[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
    }
    for(int i=1;i<=q;i++)
    {
        cin>>ask[i].x>>ask[i].y;
        ask[i].id=i;
    }
    sort(ask+1,ask+q+1);
    for(int i=1;i<=q;i++)
    {
        if(ask[i].x!=ask[i-1].x)
        {
            for(int j=1;j<=m;j++) vis[j]=0,dis[j]=1e9;
            dis[ask[i].x]=0;
            priority_queue<PII,vector<PII>,greater<PII>> pq;
            pq.push({0,ask[i].x});
            while(pq.size())
            {
                int u=pq.top().Se,d=pq.top().Fi;
                //cout<<"u:"<<u<<" dis:"<<d<<endl;
                pq.pop();
                if(vis[u]) continue;
                vis[u]=1;
                for(PII qwq:edge[u])
                {
                    int v=qwq.Fi,len=qwq.Se;
                    //cout<<u<<"->"<<v<<" "<<len<<endl;
                    if(dis[v]>dis[u]+len)
                    {
                        dis[v]=dis[u]+len;
                        pq.push({dis[v],v});
                    }
                }
            }
            ans[ask[i].id]=dis[ask[i].y]+w[ask[i].x]+w[ask[i].y];
        }
        else
        {
            ans[ask[i].id]=dis[ask[i].y]+w[ask[i].x]+w[ask[i].y];
        }
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    /*
    0 4 5 20 2
    1 1 1 1 1
    2 1 4 2 4
    2 1 3 4 2
    2 2 5 3 2
    2 4 6 5 1
    1 5
    1 3
    */
}
void subtask1()
{
    int dis[510][510];
    for(int i=1;i<=500;i++)for(int j=1;j<=500;j++) dis[i][j]=1e9;
    for(int i=0;i<=500;i++) dis[i][i]=0;
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
        for(int j=1;j<=k;j++)
        {
            for(int p=1;p<=k;p++)
            {
                if(j==p) continue;
                dis[a[i][j]][a[i][p]]=min(dis[a[i][j]][a[i][p]],t[i][j]+t[i][p]);
            }
        }
    }
    for(int p=1;p<=m;p++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<=m;i++)
            {
                dis[i][j]=min(dis[i][p]+dis[p][j],dis[i][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<endl;
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c;
    if(7<=c&&c<=11)subtaskA();
    if(1<=c&&c<=6) subtask1();
    return 0;
}
/*

思路
考虑n,k,较小时
暴力建边
1->2->3->4可以是为人以两个点连接一条长度为ti+tj的边
复杂度m^3（弗洛伊德）
考虑特殊性质A，因为最多经过两个节点，因此边长直接是t1+t2
因为最多只有m（《=1000）个节点，每个节点跑一次dij，复杂度m*klogm
RP++

*/
