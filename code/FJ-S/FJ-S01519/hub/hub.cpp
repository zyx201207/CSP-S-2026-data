#include<bits/stdc++.h>
using namespace std;
int n,k;
bool b[100001];
bool vis[100001];
vector<int> to[100001];
int ans;
int dfs(int u)
{
	if(b[u])
	{
		vis[u]=1;
		return 0;
	}
	vis[u]=1;
	int len=to[u].size();
	int ans=1000;
	for(int i=0;i<len;i++)
	{
		if(!vis[to[u][i]])
		{
//			if(!dfs(to[u][i]))cout<<"YES";
			ans=min(ans,dfs(to[u][i])+1);
		}
	}
	return ans;
}
void dg(int now,int Uw)
{
	if(now==n+1)
	{
		if(Uw!=k)return;
		int ans1=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)vis[j]=0;
			ans1=max(ans1,dfs(i));
		}
		ans=min(ans,ans1);
		return;
	}
	b[now]=0;
	dg(now+1,Uw);
	b[now]=1;
	dg(now+1,Uw+1);
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--)
	{
		ans=100000;
		scanf("%d%d",&n,&k);
		int u,v;
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			to[u].push_back(v);
			to[v].push_back(u);
		}
		dg(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
