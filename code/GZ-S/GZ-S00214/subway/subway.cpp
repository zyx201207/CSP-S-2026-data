//GZ-S00214 遵义四中 安睿峰
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[510],x,y;
long long ans,dp[510][510];
vector<int>a[500010];
vector<long long>t[500010];
int in()
{
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in();n=in();m=in();d=in();q=in();
	for(int i=1;i<=m;i++)  w[i]=in();
	for(int i=1;i<=n;i++)
	{
		k[i]=in();
		for(int j=1,s1,s2;j<=k[i];j++)
		{
			s1=in();s2=in();
			a[s1].push_back(i);
			t[s1].push_back(s2);
		}
	}
	
	memset(dp,0x3f3f3f3f,sizeof(dp));
	for(int i=1;i<=n;i++)  dp[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			for(int o=j+1;o<a[i].size();o++)
			{
				dp[a[i][j]][a[i][o]]=dp[a[i][o]][a[i][j]]=min(dp[j][o],t[i][j]+t[i][o]);
			}
		}
	}
	for(int o=1;o<=n;o++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)  dp[i][j]=min(dp[i][j],dp[i][o]+dp[o][j]);
		}
	}
	
	while(q--)
	{
		cin>>x>>y;ans=1e18;
		for(int i=0;i<a[x].size();i++)  for(int j=0;j<a[y].size();j++)  ans=min(ans,t[x][i]+t[y][j]+dp[a[x][i]][a[y][j]]);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
