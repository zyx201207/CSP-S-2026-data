//GZ-S00027 ½ªÔ£Î°
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,n,m,d,q;
int dp[3005][3005];
int w[500005];
int k[500005];
vector<int> a[500005];
vector<int> t[500005];
vector<pair<int,int>> v[500005];
void floydd()
{
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			for(int y=1;y<=k[i];y++)
			{
				if(j==y) continue;
//				cout<<a[i][j];
				dp[a[i][j]][a[i][y]]=min(dp[a[i][j]][a[i][y]],t[i][j]+t[i][y]);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		dp[i][i]=1;
	}
	for(int y=1;y<=m;y++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][y]+dp[y][j]);
			}
		}
	}
	return ;
}
bool in[500005];
void djs(int x)
{	
	memset(in,0,sizeof(in));
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,x});
	while(q.size())
	{
		auto k=q.top();
		q.pop();
		if(in[k.second]) continue;
		in[k.second]=1;
		for(auto i:v[k.second])
		{
			if(k.first+i.second<dp[x][i.first])
			{
				dp[x][i.first]=k.first+i.second;
				q.push({k.first+i.second,i.first});
			}
		}
	}
	return ;
}
void djsz()
{
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			for(int y=1;y<=k[i];y++)
			{
				if(j==y) continue;
				v[a[i][j]].push_back({a[i][y],t[i][j]+t[i][y]});
			}
		}
	}
	for(int i=1;i<=m;i++) djs(i);
	return ;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		a[i]={0};
		t[i]={0};
		for(int j=1;j<=k[i];j++)
		{
			int aa,tt;
			scanf("%lld%lld",&aa,&tt);
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	if(m<=400)
	{
		floydd();
	}
	else 
	{
		djsz();
	}
	while(q--)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",dp[x][y]+w[x]+w[y]);
	}
	return 0;
}

