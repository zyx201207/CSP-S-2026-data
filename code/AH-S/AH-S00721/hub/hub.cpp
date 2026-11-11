#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,minn=0x7fffffff;
bool f[5005][5005];
void dfs(int step,int cnt,int maxn)
{
	if(step==n)
	{
		minn=min(maxn,minn);
		return;
	}
	if(cnt>k)
		return;
	for(int i=1;i<=n;i++)
		if(f[step][i])
			dfs(step+1,cnt+1,max(maxn,abs(step-i)));
	dfs(step+1,cnt,maxn);
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
		cin>>n>>k;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			f[u][v]=1;
			f[v][u]=1;
		}
		dfs(1,0,-0x7fffffff);
		cout<<minn<<endl;
	}
	return 0;
}
