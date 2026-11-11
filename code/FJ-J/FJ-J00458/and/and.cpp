#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int z=1;z<=n;z++)
	{
		cin>>a[z];
	}
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		long long da=-1;
		for(long long z=1;z<=n;z++)
		{
			for(long long y=z+1;y<=n;y++)
			{
				if((a[z]&a[y])>=da)
				{
					da=(a[z]&a[y]);
				}
			}
		}
		cout<<da;
		return 0;
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(long long z=1;z<=m-1;z++)
	{
		ans=(ans&a[n-z]);
	}
	cout<<ans;
	return 0;
}
