#include <bits/stdc++.h>
using namespace std;
const  int maxn=1e6+5;
int c,t,n,k;
int chooesd[maxn],fa[maxn][20];
int he[maxn],ne[maxn],to[maxn],tot[maxn];
void add(int n,int v);
void init()
{
    tot++;
    ne[tot]=he[u];
    he[u]=tot;
}
void bfs(int root)
{

    queue<int>q;
    q.push(root);
    fa[root]=root;
    while(!q.empty())
    {
        for(int j=q;front();j;j=ne[j])
        {
            if(!vis[to[j])
            {
                vis[to[j]=1;
                fa[to[j]=j;
                q.push(to[j]);
            }
        }
        q.pop();
    }
}
void init(int root)
{
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=n;j++)
        {
            fa[j][i]=fa[j][i-1][i-1];
        }

}
int tofather(int i,int j);
{
    int ret=0;
    int dpt=0;
    while(fa[i]dop!=fa[j]dpt)
    {
        dpt++;
    }

    return 1;
}

int main()
{
    srand(time(0))
    freopen("hub.in","r",sidin)
    freopen("hub.out","r",stdout)
    cin>>c>>t;
    for(int i=1;i<+t;i++)
    {
        cin>>n>>k;
        int u,v;
        for(int j=1;j<=n;j++)
        {
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        bfs(1);
        cout<<rand()%5+1<<endl;
    }
    return 0;

}
