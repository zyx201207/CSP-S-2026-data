#include <bits/stdc++.h>
using namespace std;
long long n,m,a[505050]={0},ans=1,w,z,x,k=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	x=m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n>5000)
	{
		for(int i=1;i<n;i++)
		{
			if(m<(i*(a[i+1]-a[i]))) break;
			m-=(i*(a[i+1]-a[i]));
			ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int j=1;j<n;j++)
	{
		long long sum=1;
		m=x;
		for(int i=1;i<=n,i+j<n;i++)
		{
			if(m<(i*(a[i+j]-a[i+j-1]))) break;
			m-=(i*(a[i+j]-a[i+j-1]));
			sum++;
		}
		ans=max(ans,sum);
	}
	cout<<min(ans,n);
	return 0;
}