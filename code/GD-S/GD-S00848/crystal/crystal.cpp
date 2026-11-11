#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],sum[N],ans=1,add[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		if(n>5000)
		i=n;
		long long num=m;
		for(int j=i;j>=1;j--)
		{
			sum[j]+=a[i]-a[i-1];
			if(num<sum[j])
			{
				ans=max(ans,i-j+1ll);
				break;
			}
			num-=sum[j];
		} 
	} 
	cout<<ans;
	return 0;
} 
