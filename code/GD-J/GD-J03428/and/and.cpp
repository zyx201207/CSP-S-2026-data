#include<bits/stdc++.h>
using namespace std;
int n,m,a[222222];bool v[222222];
long long ans;
void ppp(int d,long long e)
{
	if(d==m)
	{
		ans=max(e,ans);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			ppp(d+1,a[i]&e);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
	long long d=1;
	for(int i=0;i<32;i++)d*=2;
	if(m==1)
	{
		cout<<a[0];return 0;
	}
	if(m==2)
	{
		ans=d;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j!=i)ans=max(ans,(long long)a[i]&a[j]);
			}
		}
		cout<<ans;return 0;
	}
	if(m==n)
	{
		ans=d;
		for(int i=0;i<n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;return 0;
	}
	if(m==n-1)
	{
		long long g=d;
		for(int i=0;i<n;i++)
		{
			g&=a[i];
		}
		for(int i=0;i<n;i++)
		{
			ans=max(ans,g|~a[i]);
		}
		cout<<ans;
		return 0;
	}
	ppp(0,d-1);
	cout<<ans;
}
