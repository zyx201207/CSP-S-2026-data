#include <bits/stdc++.h>
#define int long long
using namespace std;
char x;
int m;
int n,a[1000005],b[1000005],sum=0;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=x;
		b[i]=m;
	}
	for(int i=1;2*i<=n;i++)
	{
		if(a[i]==a[n-i+1])
		{
			if(b[i]!=b[n-i+1])
				sum+=a[i];
		}
		else if(a[i]>a[n-i+1])
		{
			if(b[i]!=b[n-i])
			{
				sum+=a[n-i+1];
				b[i]=a[n-i+1]+a[n-i];
			}
			else
			{
				sum+=a[n-i+1];
				b[i]=a[n-i+1]+a[n-i];
			}
		}
	}
	cout<<sum;
	return 0;
}

