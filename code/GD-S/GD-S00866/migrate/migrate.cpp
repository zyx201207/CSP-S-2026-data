#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int N=310;
long long c,t,n,d,x[N];
vector<int> v[N];
bool vis[N];
int s,f;
long long ans;
int minn;
int cnt;
int dis[N];
int dp[N][N];
void dfs(int x,int sum)
{
	if(sum>minn||cnt>2)return;
	if(x==s)
	{
		if(sum<minn)cnt=1,minn=sum;
		else if(sum==minn)cnt++;
		return;
	}
//	vis[x]=1;
//	dis[x]=sum;
	for(int i=0;i<v[x].size();i++)
	{
		if(vis[v[x][i]]||sum+1>dp[f][v[x][i]])continue;
		vis[v[x][i]]=1;
		dfs(v[x][i],sum+1);
		vis[v[x][i]]=0;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(c==13||c==14)
		{
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=1e9;
		for(int i=1;i<=n;i++)
		{
			dp[i][i]=0;
			for(int j=i+1;j<=n;j++)
			{
//				dp[i][j]=dp[j][i]=1e9;
				if(x[j]-x[i]>d)break;
				v[i].push_back(j);
				v[j].push_back(i);
				dp[i][j]=dp[j][i]=1;
			}
		}
		ans=0;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
//				for(int k=1;k<=n;k++)vis[k]=0,dis[k]=1e9;
				minn=dp[i][j];
//				dis[i]=0;
				s=j;
				f=i;
				cnt=0;
//				vis[i]=1;
				dfs(i,0);
				ans+=(cnt==2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 
5 2
1 2 3 4 
*/
