#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,q,a[2000005],ans[2000005],dp[2000005],vis[2000005];
struct N{
	int y,w;
};
bool operator < (N x,N y){
	return x.w<y.w;
}
vector<N>l[2000005];
void dij(int s)
{
	priority_queue<N>q;
	q.push({s,0});
	dp[s]=0;
	ans[s]=1;
	while(q.size())
	{
		int x=q.top().y;
		q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		for(int i=0;i<l[x].size();i++)
		{
			int y=l[x][i].y,w=l[x][i].w;
			if(dp[y]>dp[x]+w)
			{
				dp[y]=dp[x]+w;
				ans[y]=ans[x];
				q.push({y,dp[y]});
			}
			else if(dp[y]==dp[x]+w)
			{
				ans[y]+=ans[x];
			}
		}
	}
}
int d;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int f=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			l[i].clear(); 
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j and abs(a[j]-a[i])<=d)
					l[i].push_back({j,1});
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				vis[j]=0,dp[j]=1e18;
			dij(i);
			for(int j=i+1;j<=n;j++)
				if(ans[j]==2)
					sum++;
		}
		cout<<sum<<'\n';
	}
	return 0;
}

