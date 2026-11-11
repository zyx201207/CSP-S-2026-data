#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N=5e5+5;

long long n,m,ans,cc,a[N],s[N],b[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				a[j]=b[j]-b[i];
				s[j]=s[j-1]+a[j];
			}
			for(int j=1;j<=i;j++)
			{
				if(m+s[i]-s[j-1]>=0)
				{
					ans=max(ans,(long long)i-j+1);
					break;
				}
			}
		}
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			cc+=i;
			if(cc*(a[2]-a[1])<=m)
			{
				ans=i+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
