#include<bits/stdc++.h>
using namespace std;
long long n,m,t,a[600000],sum=1,maxx=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	t=m;
	for(int i=n;i>=1;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(a[j]!=a[i])
			{
				if(t>=a[i]-a[j])
				{
					t=t-a[i]+a[j];
					sum++;
				}
			}
			else if(a[j]==a[i]) sum++;
		}
		t=m;
		maxx=max(maxx,sum);
		sum=1;
	}
	cout<<maxx;
	return 0;
}
