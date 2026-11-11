#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N],e,ans,minx,vis[N],n,d;
void dfs(int x,int dist)
{
	if(x==e)
	{
		if(dist==minx) ans++;
		if(dist<minx)
		{
			minx=dist;
			ans=1;
		}
	}
	for(int i=x+1;i<=n;i++)
		if(a[i]-a[x]<=d)
			dfs(i,dist+1);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,t,i,j,fans=0;
	cin>>c>>t;
	while(t--)
	{
		fans=0;
		cin>>n>>d;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
			{
				minx=INT_MAX;
				e=j;
				memset(vis,0,sizeof(vis));
				dfs(i,0);
				if(ans==2) fans++;
			}
		cout<<fans<<'\n';	
	}
	return 0;
}
