#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,m;
long long a[N];
long long b[N];
long long f[5005][5005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>5005)
	{
		long long cnt=0;
		int k=a[2]-a[1];
		while(m>=0)
		{
			m=m-(++cnt)*k;
			if(cnt>=n)
			{
				cout<<n;
				return 0;
			}
		}
		cout<<cnt;
		return 0;
	}
	else
	{
	
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			f[i][j]=b[j-1]*(j-i)+f[i][j-1];
		}
	}
	
	for(int i=n-1;i>=0;i--)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(f[j][j+i]<=m)
			{
				cout<<i+1;
				return 0;
			}
		}
	}
	
	}
}
