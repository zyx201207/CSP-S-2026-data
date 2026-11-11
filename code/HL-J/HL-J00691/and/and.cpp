#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=-1e9;
	cin>>n>>m;
	ll a[n+5]={};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=a[1];
	if(m==n)
	{
		for(int i=2;i<=n;i++)
		{
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++)
	{
		int sum=a[i];
		for(int j=i;j<=i+m;j++)
		{
			sum=sum&a[j];
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
