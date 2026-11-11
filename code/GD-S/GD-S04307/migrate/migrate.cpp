#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define il inline
using namespace std;
const int maxn=2e6+10;
int o,n,m,ans;
int a[maxn],b[maxn],c[maxn],mn[5010][5010],dp[5010][5010];
void _main()
{
	cin>>n>>m,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,j=0;i<=n;i++)
	{
		j=max(j,i);
		while(j<n&&a[j+1]-a[i]<=m) j++;
		b[i]=j;
	}
	if(o<=10)
	{
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) mn[i][j]=1e9,dp[i][j]=0;
		for(int len=1;len<=n;len++)
		{
			for(int i=1;i+len<=n;i++)
			{
				int j=i+len;
				if(b[i]>=j){mn[i][j]=dp[i][j]=1;continue;}
				if(len==1) continue;
				mn[i][j]=mn[b[i]][j]+1;
				dp[i][j]=dp[b[i]][j];
				if(b[i]-1>i&&mn[i][b[i]-1]+mn[b[i]-1][j]==mn[i][j]) dp[i][j]+=dp[b[i]-1][j];
				if(b[i]-2>i&&mn[i][b[i]-2]+mn[b[i]-2][j]==mn[i][j]) dp[i][j]+=dp[b[i]-2][j];
				dp[i][j]=min(dp[i][j],3ll);
				if(dp[i][j]==2&&mn[i][j]<n) ans++;
			}
		}
		cout<<ans<<endl;
		return;
	}
	if(o<=12)
	{
		if(n==1){cout<<0<<endl;return;}
		int d=a[2]-a[1],p=m/d;
		if(p<=1){cout<<0<<endl;return;}
		cout<<max(n-(p*2-1),0ll)<<endl;
		return;
	}
	if(o<=14)
	{
		int p=1;ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]-a[1]<=m&&a[n]-a[i]<=m) p=i;
		if(p==1||p==n){cout<<0<<endl;return;}
		if(p>2)
		{
			int x=0,y=n+1;
			for(int i=1;i<=n;i++)
				if(a[p+1]-a[i]>m) x=i;
			for(int i=n;i>=1;i--)
				if(a[i]-a[p-2]>m) y=i;
			ans+=x*(n-y+1); 
		}
		if(p<n-1)
		{
			int x=0,y=n+1;
			for(int i=1;i<=n;i++)
				if(a[p+2]-a[i]>m) x=i;
			for(int i=n;i>=1;i--)
				if(a[i]-a[p-1]>m) y=i;
			ans+=x*(n-y+1);
		}
		cout<<ans<<endl;
		return;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _;cin>>o>>_;
	while(_--) _main();
}
