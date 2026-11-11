#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200000+10],ma=LLONG_MIN;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>ma)
			{
				ma=a[i];
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(ma<(a[i]&a[j]))
				{
					ma=(a[i]&a[j]);
				}
			}
		}
		cout<<ma;
		return 0;
	}

	return 0;
}
