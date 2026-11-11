#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 5e5 + 10;

long long n,m;
long long a[MAXN],sum[MAXN],mmx[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	sum[0]=0;
	mmx[0]=0;
	for(long long i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];	
		mmx[i]=max(mmx[i-1],a[i]);
	}
	
	long long i=1,j=1; 
	long long ans=0;
	for(j=1;j<=n;j++) 
	{
		long long cost=mmx[j]*(j-i+1)-(sum[j]-sum[i-1]); 
		while(cost > m && i<=j) 
		{
			i++;
			cost=mmx[j]*(j-i+1)-(sum[j]-sum[i-1]);
		}
		ans=max(ans,j-i+1);
	}
	
	cout<<ans<<endl;
	
	return 0;
}
