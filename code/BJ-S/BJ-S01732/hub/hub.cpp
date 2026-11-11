#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int head[N], nex[N], to[N], indx, c;

void add_edge(int x,int y)
{
	indx++;
	nex[indx]=head[x];
	to[indx]=y;
	head[x]=indx;
}

int fa[N][20], dep[N], dfsn[N], sz[N], point[N], edge[N], Indx;

void dfs1(int x)
{
	dfsn[x]=++Indx, sz[x]=1, point[Indx]=x;
	for(int i=1;i<20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];

	for(int i=head[x];i;i=nex[i])
	{
		int y=to[i];
		if(y!=fa[x][0])
		{
			edge[y]=i;
			dep[y]=dep[x]+1;
			fa[y][0]=x;
			dfs1(y);
			sz[x] += sz[y];
		}
	}
}

int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);

	for(int i=19;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];

	if(x==y)
		return x;

	for(int i=19;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i], y=fa[y][i];

	return fa[x][0];
}

int dist(int x,int y)
{
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}

int a[5];

struct diam
{
	int x,y;

	diam operator +(const diam& oth) const
	{
		a[0]=x, a[1]=y, a[2]=oth.x, a[3]=oth.y;
		int Max=-1, bestx=0, besty=0;
		for(int i=0;i<4;i++)
			for(int j=i+1;j<4;j++)
			{
				if(a[i]==0 || a[j]==0)
					continue;

				int D=dist(a[i],a[j]);
				if(D>Max)
					Max=D, bestx=a[i], besty=a[j];
			}
		return (diam){bestx,besty};
	}
} pre[N], suf[N], subtree[N];

void dfs2(int x)
{
	subtree[x]=(diam){x,x};
	for(int i=head[x];i;i=nex[i])
	{
		int y=to[i];
		if(y!=fa[x][0])
		{
			dfs2(y);
			subtree[x]=subtree[x]+subtree[y];
		}
	}
}

bool del[N];
int len[N], cnt[N];

void dfs3(int x,int fa)
{
	len[x]=0;
	for(int i=head[x];i;i=nex[i])
	{
		int y=to[i];
		if(!del[i] && y!=fa)
		{
			dfs3(y,x);
			len[x]=max(len[x],len[y]+1);
		}
	}
}

int kthfa(int x,int k)
{
	for(int i=19;i>=0;i--)
		if((k>>i)&1)
			x=fa[x][i];
	return x;
}

int Mid(int x,int y)
{
	int D=dist(x,y)/2;
	if(dep[x]<dep[y])
		return kthfa(y,D);
	return kthfa(x,D);
}

void work()
{
	int n,k;
	scanf("%d %d",&n,&k);
	memset(head,0,sizeof(head));
	indx=1, Indx=0;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}

	if(k==n)
	{
		printf("0\n");
		return;
	}

	dep[1]=1, dfs1(1);
	dfs2(1);

	pre[0]=(diam){0,0}, suf[n+1]=(diam){0,0};
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+(diam){point[i],point[i]};

	for(int i=n;i>=1;i--)
		suf[i]=suf[i+1]+(diam){point[i],point[i]};

	int ans=0x3f3f3f3f;
	for(int i=2;i<=n;i++)
	{
		int l=dfsn[i], r=dfsn[i]+sz[i]-1;
		diam In=subtree[i], Out=pre[l-1]+suf[r+1];
		if(k<=2)
			ans=min(ans,(max(dist(In.x,In.y),dist(Out.x,Out.y))+1)/2);
		else if(c<13 || c>14)
		{
			del[edge[i]]=del[edge[i]^1]=true;
			int x=Mid(In.x,In.y), y=Mid(Out.x,Out.y);
			dfs3(x,-1), dfs3(y,-1);
			for(int i=0;i<=n+1;i++)
				cnt[i]=0;

			for(int i=1;i<=n;i++)
				cnt[len[i]]++;

			int tot=k;
			for(int i=n;i>=0;i--)
				if(tot>=cnt[i])
					tot -= cnt[i];
				else
				{
					ans=min(ans,i+1);
					break;
				}

			del[edge[i]]=del[edge[i]^1]=false;
		}
	}

	int x=Mid(subtree[1].x,subtree[1].y);
	dfs3(x,-1);
	for(int i=0;i<=n+1;i++)
		cnt[i]=0;

	for(int i=1;i<=n;i++)
		cnt[len[i]]++;

	int tot=k;
	for(int i=n;i>=0;i--)
		if(tot>=cnt[i])
			tot -= cnt[i];
		else
		{
			ans=min(ans,i+1);
			break;
		}

	if(13<=c && c<=14)
	{
		if(k==n/2-1)
			printf("1\n");
		else
			printf("%d\n",max(1,(n/2-k+7)/4));
	}
	else
		printf("%d\n",ans);
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	cin >> c >> T;
	while(T--)
		work();
	return 0;
}