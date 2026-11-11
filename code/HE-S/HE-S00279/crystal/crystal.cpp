#include<bits/stdc++.h> 
using namespace std;
long long n,m,m2;
long long a[100010];
long long maxn = -1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i = a[1];i<=a[n];i++)
	{
		m2 = m;
		int bz = -10;
		for(int x = 1;x<n;x++)
		{
			if(a[x]==i)
			{
				bz=x;
			}
			if(a[x]<i&&a[x+1]>i)
			{
				bz = x+1;
			}
		}
		long long sum = 0;
		for(int j = 0;j<=bz;j++)
		{
			if(m2>=a[bz]-a[bz-j])
			{
				m2-=a[bz]-a[bz-j];
				sum++;
			}
		}
		maxn = max(maxn,sum);
	}
	cout<<maxn;
	
	return 0;
}
