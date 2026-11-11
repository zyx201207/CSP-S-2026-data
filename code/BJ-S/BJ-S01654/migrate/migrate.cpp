#include<bits/stdc++.h>
using namespace std;
const int maxn1=5e3+5;
const int maxn2=2e6+5;
const long long INF=INT_MAX;
long long a[maxn1],a1[maxn2];
vector<int> g[maxn1];
int dep[maxn1][maxn1];
bool vis[maxn1];
int ans[maxn1][maxn1],dp[maxn1][maxn1];
queue<int> q;
int n;
long long d;
void bfs(int st)
{
	for(int i=1;i<=n;i++)vis[i]=0;
	q.push(st);
	dep[st][st]=0;
	vis[st]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:g[u])
		{
			if(vis[v])continue;
			dep[st][v]=dep[st][u]+1;
			vis[v]=1;
			q.push(v);
		}
	}
}
void dfs(int st,int u,int l)
{
	if(l==dep[st][u]&&u!=st)ans[st][u]++;
	
	for(auto v:g[u])
	{
		dfs(st,v,l+dep[u][v]);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			long long k=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a1[i];
			k=d/(a1[2]-a1[1]);
			if(k<=1||2*k-1>=n)
			{
				cout<<"0\n";
				continue;
			}
			cout<<n-(2*k-1)<<"\n";
		}
		return 0;
	}
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dep[i][j]=INF;
				dp[i][j]=0;
			}
			dp[i][i]=1;
		}
		for(int i=1;i<=n;i++)cin>>a[i],g[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)g[i].push_back(j);
				
			}
		}
		for(int i=1;i<n;i++)bfs(i);
		for(int i=1;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(a[k]-a[j]<=d&&dep[i][j]+dep[j][k]==dep[i][k])dp[i][k]+=dp[i][j];
				}
			}
		}
		int s=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(dp[i][j]==2)s++;
			}
		}
		
		
		cout<<s<<"\n";
		
	}
	return 0;
}
