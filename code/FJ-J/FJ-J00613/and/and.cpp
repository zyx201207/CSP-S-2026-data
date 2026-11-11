#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000005];
bool cmp(long long x,long long y) 
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1)
	{
		long long maxx=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		long long sum=a[1];
		for(int i=2;i<=n;i++) sum=sum&a[i];
		cout<<sum;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		long long maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1,cmp);
	long long sum=a[1];
	for(int i=1;i<=m;i++) sum&=a[i];
	cout<<sum;
	return 0;
}
