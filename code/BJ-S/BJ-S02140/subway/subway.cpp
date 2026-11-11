#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],k1[510],b2[N][21],t2[N][21],cnt[N];
long long dp[510][510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp,0x3f,sizeof(dp));
	int c,m,n,d,q,i,j,k,b,t,l,r;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		cin>>k1[i];
		for(j=1;j<=k1[i];j++)
		{
			cin>>b>>t;
			cnt[b]++;
			b2[b][cnt[b]]=i;
			t2[b][cnt[b]]=t;
		}
	}
	for(i=1;i<=n;i++)
		dp[i][i]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=cnt[i];j++)
		{
			for(k=j+1;k<=cnt[i];k++)
				dp[b2[i][j]][b2[i][k]]=dp[b2[i][k]][b2[i][j]]=t2[i][j]+t2[i][k];
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
					continue;
				if(dp[i][k]+dp[k][j]<dp[i][j])
					dp[i][j]=dp[i][k]+dp[k][j];
			}
		}
	}
	for(i=1;i<=q;i++)
	{
		cin>>l>>r;
		long long ans=1e18;
		for(j=1;j<=cnt[l];j++)
		{
			for(k=1;k<=cnt[r];k++)
			{
				long long x=t2[l][j]+dp[b2[l][j]][b2[r][k]]+t2[r][k];
				ans=min(ans,x);
			}
		}
		cout<<ans+a[l]+a[r]<<'\n';
	}
	return 0;
}
