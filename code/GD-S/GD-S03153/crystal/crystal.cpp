#include <bits/stdc++.h>
using namespace std;
int n,a[500001],ans;
long long m;
void count(int a)
{
	ans=0;
	int num=0;
	while(num<m)
	{
		num=a*ans+a+num;
		ans++;
	}
	if(num<=m)ans++;
	cout<<ans;
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		a[i-1]=a[i]-a[i-1];
	}
	bool o1=1;
	for(int i=2;i<n;i++)
	{
		if(a[i]!=a[i-1])o1=0;
	}
	if(o1)
	{
		count(a[1]);
		return 0;
	}
	for(int i=n-2;i>=1;i--)
	{
		a[i]=a[i]+a[i+1];
	}
	a[n]=0;
	for(int l=1;l<n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			int num=0;
			bool ok=1;
			for(int i=l;i<r;i++)
			{
				num+=a[i]-a[r];
				if(num>m)
				{
					if(i!=r)
					  ok=0;
					ans=max(ans,i-l);
					break;
				}
			}
			if(!ok)break;
			ans=max(ans,r-l+1);
		}
	}
	cout<<ans;
}
