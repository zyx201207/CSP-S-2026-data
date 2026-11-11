#include<cstdio>
using namespace std;
int n,m;
int a[500005],cnt[300005];
struct node
{
	int ls,rs,w,cnt,flag;
}T[10000005];
int root[500005],tot=0;
bool vis[10000005];
int Ans[300005];
void update(int o,int &u,int l,int r,int pos)
{
	if(!u)
	{
		u=++tot;
	}
	if(l==r)
	{
		T[u].cnt=1;
		T[u].w=1;
		T[u].flag=l;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid)
	{
		T[u].rs=T[o].rs;
		T[T[o].rs].cnt++;
		T[u].ls=++tot;
		T[T[u].ls]=T[T[o].ls];
		T[T[u].ls].cnt=0;
		update(T[o].ls,T[u].ls,l,mid,pos);
	}
	else
	{
		T[u].ls=T[o].ls;
		T[T[o].ls].cnt++;
		T[u].rs=++tot;
		T[T[u].rs]=T[T[o].rs];
		T[T[u].rs].cnt=0;
		update(T[o].rs,T[u].rs,mid+1,r,pos); 
	}
}
void pushdown(int u)
{
	T[T[u].ls].cnt+=T[u].cnt;
	T[T[u].rs].cnt+=T[u].cnt;
	T[u].cnt=0;
}
void dfs(int u,int l,int r)
{
	if(!u)
	{
		return;
	}
	if(vis[u])
	{
		return;
	}
	vis[u]=true;
	if(l==r)
	{
		Ans[l]+=T[u].cnt*T[u].w;
		return;
	}
	pushdown(u);
	int mid=(l+r)/2;
	dfs(T[u].ls,l,mid);
	dfs(T[u].rs,mid+1,r);
}
int q[10000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--)
	{
		if(!cnt[a[i]])
		{
			update(root[i+1],root[i],1,m,a[i]);
		}
		else
		{
			root[i]=root[cnt[a[i]]];
			T[root[i]].cnt++;
		}
		cnt[a[i]]=i;
	}
	int h=1,t=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[root[i]])
		{
			q[++t]=root[i];
			vis[root[i]]=1;		
		}
	}
	while(h<=t)
	{
		int u=q[h++];
		if(!T[u].flag)
		{
			pushdown(u);
		}
		else
		{
			Ans[T[u].flag]+=T[u].cnt*T[u].w; 
		}
		if(T[u].ls&&!vis[T[u].ls])
		{
			vis[T[u].ls]=1;
			q[++t]=T[u].ls;
		}
		if(T[u].rs&&!vis[T[u].rs])
		{
			vis[T[u].rs]=1;
			q[++t]=T[u].rs;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",Ans[i]);
	}
	return 0;
}
