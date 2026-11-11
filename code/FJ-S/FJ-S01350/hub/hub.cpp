#include<bits/stdc++.h>
using namespace std;
const int N=3000;
int c,T,n,k,uu,vv,dfn[N],pos[N],idx,dep[N],lg[N],st[20][N],ans,fa[N];
vector<int> v[N];
int lca(int x,int y)
{
	int l=pos[x],r=pos[y];
	if(l>r)
	{
		swap(l,r);
	}
	int w=lg[r-l];
	return dfn[min(st[w][l],st[w][r-(1<<w)+1])];
}
int dis(int x,int y)
{
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void dfs(int x,int f)
{
	dfn[++idx]=x;
	pos[x]=idx;
	for(auto i:v[x])
	{
		if(i!=f)
		{
			dep[i]=dep[x]+1;
			dfs(i,x);
			dfn[++idx]=x;
		}
	}
	return;
}
int Find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=Find(fa[x]);
}
void calc(int x)
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(auto j:v[i])
		{
			if((x&(1<<(i-1)))&&(x&(1<<(j-1))))
			{
				fa[Find(i)]=Find(j);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(x&(1<<(i-1)))
		{
			if(Find(i)==i)
			{
				cnt++;
			}
		}
	}
	if(cnt>2)
	{
		return;
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		int minn=n;
		for(int j=1;j<=n;j++)
		{
			if(x&(1<<(j-1)))
			{
				minn=min(minn,dis(i,j));
			}
		}
		maxx=max(maxx,minn);
	}
	ans=min(ans,maxx);
	return;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
	}
	for(int i=1;i<=n-1;i++)
	{
		cin>>uu>>vv;
		v[uu].push_back(vv);
		v[vv].push_back(uu);
	}
	idx=0;
	dfs(1,0);
	lg[1]=0;
	for(int i=2;i<=idx;i++)
	{
		lg[i]=lg[i>>1]+1;
		st[0][i]=pos[dfn[i]];
	}
	for(int i=1;i<=lg[idx];i++)
	{
		for(int j=1;j<=idx-(1<<i)+1;j++)
		{
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);	
		} 
	}
	ans=n;
	for(int i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)==k)
		{
			calc(i);
		}
	}
	cout<<ans<<"\n";
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
