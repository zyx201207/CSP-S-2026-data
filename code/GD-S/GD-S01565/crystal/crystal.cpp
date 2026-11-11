#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],num,sum,gum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long mid=(1+n)/2;
	for(long long i=1;i<=n;i++)
	{
		num=0;
		for(int i=1;i<=mid;i++)
		{
			b[i]=a[mid]-a[i];
		}
		for(int i=1;i<=mid;i++)
		{
			num+=b[i];
		}
		gum=0;
		if(num>m)
		{
			mid-=(n-mid)/2;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]+b[i]==a[mid])
				{
					gum++;
				}
			}
			sum=max(sum,gum);
			mid+=(n-mid)/2;
		}
	}
	cout<<sum;
	return 0;
}
