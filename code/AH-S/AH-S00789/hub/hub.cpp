#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v,now[105],vis[105],nowmn,mn; 
vector<long long> e[105];
void ddd(long long w)
{
	for (int i=0;i<e[w].size();i++)
	{
		if (!vis[e[w][i]]&&now[e[w][i]])
		{
			vis[e[w][i]]=1;
			ddd(e[w][i]);
		}		
	}
	return; 
}
bool check()
{
	long long cnt=0;
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
	{
		if (now[i]&&!vis[i])
		{
			cnt++;
			vis[i]=1;
			ddd(i);
		}
		if (cnt>2)
		{
			return 0;
		}
	}
	return 1;
}
void get(long long w,long long ans)
{
	if (ans>nowmn)
	{
		return;
	}
	if (now[w])
	{
		nowmn=min(nowmn,ans);
	}
	for (int i=0;i<e[w].size();i++)
	{
		if (!vis[e[w][i]])
		{
			vis[e[w][i]]=1;
			get(e[w][i],ans+1);
		}
	}
	return;
}
void sol()
{
	long long nowmx=0;
	for (int i=1;i<=n;i++)
	{
		nowmn=1e18;
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		get(i,0);
		nowmx=max(nowmx,nowmn);
	}
	mn=min(mn,nowmx);
	return;
}
void dfs(long long w,long long nowk)
{
	if (nowk>k)
	{
		return;
	}
	if (w>n)
	{
		if (nowk<k)
		{
			return;
		}
		if (check())
		{
			sol();
		}
		return;
	}
	now[w]=0;
	dfs(w+1,nowk);
	now[w]=1;
	dfs(w+1,nowk+1);
	now[w]=0;
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		mn=1e18;
		cin>>n>>k;
		for (int i=1;i<=n;i++)
		{
			e[i].clear();
		}
		for (int i=1;i<n;i++)
		{
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		cout<<mn<<"\n";
	}
	return 0;
} 
