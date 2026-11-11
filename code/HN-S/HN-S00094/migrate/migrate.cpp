#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
int c,t,n,d,x[MAXN],dis[MAXN],num[MAXN];
vector<int> G[MAXN];
void dfs(int x,int sum)
{
	if(sum==dis[x]) num[x]++;
	else if(sum<dis[x]) dis[x]=sum,num[x]=1;
	for(auto &i:G[x]) dfs(i,sum+1);
}
int main(  )
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i],G[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d) G[i].push_back(j);
				else break;
			}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) num[j]=0,dis[j]=2e9;
			dfs(i,0);
			for(int j=i+1;j<=n;j++) if(num[j]==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

