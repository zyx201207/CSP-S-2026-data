#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],sum[500005],ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) 
	{
		sum[i]=sum[i-1]+a[i];
	} 
	for(long long i=1,j=2;j<=n&&i<=n;)
	{
		if(a[j]*(j-i+1)<=sum[j]-sum[i-1]+m) 
		{
			ans=max(ans,j-i+1);
			j++;
		}
		else i++;
	}
	cout<<ans;
}
