#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,d,q,W[505005],id,idx,fa[505005][20],dis[505005],de[505005];
vector<int>e1[505005];
struct node
{
    int u,v,w;
}book[505005];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int getf(int x)
{
    if(x==fa[x][0])
        return x;
    return fa[x][0]=getf(fa[x][0]);
}
void bcj(int x,int f)
{
    if(getf(x)!=getf(f))
        fa[x][0]=f;
    return ;
}
void dfs(int x,int f)
{
    de[x]=de[f]+1;
    for(int i=0;i<e1[x].size();i+=2)
    {
        int y=e1[x][i],w=e1[x][i+1];
        if(y==f)
            continue;
        dis[y]=dis[x]+w;
        dfs(y,x);
    }
    return ;
}
void kruskal()
{
    sort(book+1,book+1+idx,cmp);
    for(int i=1;i<=n+m;i++) fa[i][0]=i;
    int cnt=0;
    for(int i=1;i<=idx;i++)
    {
        int uu=book[i].u,vv=book[i].v;
        if(getf(uu)==getf(vv))
            continue;
        else
        {
            bcj(uu,vv);
            e1[uu].push_back(vv);
            e1[uu].push_back(book[i].w);
            e1[vv].push_back(uu);
            e1[vv].push_back(book[i].w);
            cnt++;
        }
        if(cnt==n+m-1)
            break;
    }
    for(int i=0;i<e1[1].size();i+=2)
    {
        int y=e1[1][i],w=e1[1][i+1];
        dis[y]=w;
    }
    dfs(1,0);
    return ;
}
int lca(int x,int y)
{
    for(int i=1;i<=idx;i++)
        for(int j=1;j<=20;j++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
    if(de[x]<de[y]) swap(x,y);
    for(int i=20;i>=0;i--)
    {
        if(de[fa[x][i]]>=de[y])
            x=fa[x][i];
    }
    if(x==y)
        return x;
    while(fa[x][0]!=fa[y][0])
    {
        x=fa[x][0],y=fa[y][0];
    }
    return fa[x][0];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&W[i]);
	for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%lld",&k);
        id++;
        for(int j=1;j<=k;j++)
        {
            int u,w;
            scanf("%lld",&u);
            scanf("%lld",&w);
            idx++;
            book[idx].u=u;
            book[idx].v=m+id;
            book[idx].w=w;
        }
    }
    kruskal();
    while(q--)
    {
        int s,r;
        scanf("%lld%lld",&s,&r);
        printf("%lld\n",dis[s]+dis[r]-2*dis[lca(s,r)]+W[s]+W[r]);
    }
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
