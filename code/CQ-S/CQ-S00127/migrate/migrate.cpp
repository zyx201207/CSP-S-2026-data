#include<bits/stdc++.h>
using namespace std;
const int N=5010;
long long a[N];
int to[N];
int dp[N];
int c[5010];
int back[N];
void solve()
{
	int n;
	long long d;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<n and a[j+1]-a[i]<=d)
			++j;
		to[i]=j;
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n;j++)
			dp[j]=c[j]=0;
		int la=i;
		for(int j=i;j<=n;j++)
			for(int k=la+1;k<=to[j];k++)
				dp[k]=dp[j]+1,la=k;
		c[i]=1;
		for(int j=i;j<=n;j++)
			for(int k=j+1;k<=to[j];k++)
				if(dp[k]==dp[j]+1)
					c[k]+=c[j];
		for(int j=i;j<=n;j++)
			if(c[j]==2)
				ans++;
	}
	cout<<ans<<"\n";
}




int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
		solve();
	
	
	return 0;
}
