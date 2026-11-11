#include <bits/stdc++.h>
using namespace std;

int a[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,x,t=0,maxs=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		long long k=0,l=m;
		if(a[i]==a[i+1])
		{
			if(a[i]!=a[i-1]) x=i-1;
			t++;
			continue;
		}
		else if(a[i]!=a[i-1]) 
		{
			t=0;
			x=i-1;
		}
		k+=t;
		while(l>0&&x>0)
		{
			if(l>=a[i]-a[x])
			{
				k++;
				l=l-a[i]+a[x];
				x--;
			}
			else break;
		}
		k++;
		maxs=max(maxs,k);
	}
	cout<<maxs;
	return 0;
} 
