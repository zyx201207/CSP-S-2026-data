#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>
using namespace std;
int n,k,choose[2000000],vis[2000000],ans=INT_MAX;
vector<int> e[2000001];
bool inchoose(int x)
{
    for(auto to:choose)if(x==to)return true;
    return false;
}
void buildblocks(int x)
{
    vis[x]=1;
    for(auto to:e[x])if(inchoose(to))vis[to]=1;
}
int findblocks()
{
    int res=0;
    for(int i=1;i<=k;i++)
    {
        if(!vis[choose[i]])
        {
            res++;
            buildblocks(choose[i]);
        }
    }
    return res;
}
int bfs(int city)
{
    int dist=0;
    if(vis[city])return 0;
    queue<int> q;
    q.push(city);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(vis[x])break;
        for(auto to:e[x])
        {
            q.push(to);
            dist++;
        }
    }
    return dist;
}
void dfs(int pos)
{
    if(pos>k)
    {
        memset(vis,0,sizeof(vis));
        if(findblocks()>2)return;
        //cout<<"choose:";
        //for(int i=1;i<=k;i++)cout<<choose[i]<<" ";
        //cout<<"\n";
        int dist=0;
        for(int i=1;i<=n;i++)
        {
            dist=max(dist,bfs(i));
            //cout<<"vis:";
            //for(int j=1;j<=n;j++)cout<<vis[j]<<" ";
            //cout<<"\n";
        }
        ans=min(ans,dist);
    }
    for(int i=choose[pos-1]+1;i<=n;i++)
    {
        choose[pos]=i;
        dfs(pos+1);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ID,T;
    cin>>ID>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(choose,0,sizeof(choose));
        cin>>n>>k;
        for(int i=1;i<=n;i++)e[i].clear();
        ans=INT_MAX;
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1);
        cout<<ans-1<<"\n";
    }
    return 0;
}