#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=1;
int main()
{
  	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++)
	{
		long long j=i-1,xf=0,sum=1;
		while(xf+a[i]-a[j]<=m&&j>0)
			xf+=(a[i]-a[j]),j--,sum++;
		ans=max(ans,sum);
	}
	cout<<ans;
 	return 0;
}
