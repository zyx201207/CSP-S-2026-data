#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],i,j,ch,sum[500001],ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=2,j=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i]-a[i-1];
		ch=ch+(i-j)*(a[i]-a[i-1]);
		while(ch>m)
		{
			ch=ch-sum[i]+sum[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
