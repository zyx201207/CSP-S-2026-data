#include<bits/stdc++.h>
using namespace std;
vector<int> a[1000010];
int f[110],maxn,cnt2[110],ans,n,k;
bool vis[110],flag[110];
int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	return f[x]=find(f[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)
	{
		f[fy]=fx;
	}
	return;
}
void DFS2(int t,int fa,int cnt)
{
	maxn=max(maxn,cnt);
	for(int i=0;i<a[t].size();i++)
	{
		if(a[t][i]==fa)
		{
			continue;
		}
		DFS2(a[t][i],t,cnt+1);
	}
	return;
}
void DFS(int t,int fa,int cnt)
{
	if(cnt==k)
	{
		maxn=0;
		int tmp=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=i;
			cnt2[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(flag[i])
			{
				for(int j=0;j<a[i].size();j++)
				{
					if(flag[a[i][j]])
					{
						merge(i,a[i][j]);
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i]==i)
			{
				cnt2[i]++;
				if(cnt2[i]==2)
				{
					tmp++;
				}
			}
		}
		if(tmp>2)
		{
			return;
		}
		for(int i=1;i<=n;i++)
		{
			if(cnt2[i]==1)
			{
				DFS2(i,0,0);
			}
		}
		ans=min(ans,maxn);
	}
	vis[t]=true;
	for(int i=0;i<a[t].size();i++)
	{
		if(a[t][i]==fa)
		{
			continue;
		}
		flag[t]=true;
		DFS(a[t][i],t,cnt+1);
		flag[t]=false;
		DFS(a[t][i],t,cnt);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			flag[t]=true;
			DFS(i,i,cnt+1);
			flag[t]=false;
			DFS(i,i,cnt);
		}
	}
	vis[t]=false;
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		memset(flag,false,sizeof(flag));
		ans=INT_MAX;
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		DFS(1,0,0);
		cout<<ans<<'\n';
	}
}
