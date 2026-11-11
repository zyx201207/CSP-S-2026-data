#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans = -1,f1=1,f2=1,hhh;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i]!=i)	f1=0;
		if(a[i+1]-a[i]!=a[i]-a[i-1] &&i!=1&&i!=n)	f2=0;
		else	hhh=a[i]-a[i-1];
	}
	if(f1==1)
	{
		int jia = 2,tool=0;
		while(1)
		{
			tool+=jia;
			if(tool>=m)
			{
				cout << jia;
				return 0;
			}
			jia++;
		}
	}
	if(f2==1)
	{
		int jia = 1,tool=0;
		while(1)
		{
			for(int i = 1;i <= jia*2;i++)
			{
				tool+=jia;
				if(tool>=m)
				{
				cout << jia;
				return 0;
				}
			}
			jia++;
		}
	}
	sort(a+1,a+n+1);
	for(long long i = 1;i <= n;i++)
	{
		if(a[i+1]==a[i])	continue;
		long long sum=0;
		for(int j = 1;j <= i;j++)
		{
			sum+=(a[i]-a[j]);
		}
		if(sum>m)	continue;
		ans = max(ans,i);
	}
	cout << ans;
	return 0;
}
