#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,sum;
long long a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1,j=2;j<=n;)
	{
		if(sum+(j-i)*(a[j]-a[j-1])<=m)
		{
			sum=sum+(j-i)*(a[j]-a[j-1]);
			ans=max(ans,j-i+1);
			j++;
		}
		else
		{
			sum-=(a[j-1]-a[i]);
			i++;
		}
	}
	cout<<ans;
	return 0;
}
