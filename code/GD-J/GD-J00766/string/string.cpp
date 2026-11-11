#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
char c[N];
long long sum[N],sum1[N],ans,l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=1;i--)
	{
		sum[i]=sum[i+1]+a[i];
	}
	l=1,r=n;
	while(l<r)
	{
		if(a[l]>=a[r])
		{
			ans+=(c[l]!=c[r])*a[r];
			a[l]-=a[r--];
		}
		else
		{
			ans+=(c[l]!=c[r])*a[l];
			a[r]-=a[l++];
		}
	}
	cout<<ans;
	return 0;
} 
