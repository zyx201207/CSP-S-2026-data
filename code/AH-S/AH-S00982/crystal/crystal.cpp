#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
long long m;
long long a[1000000],k=0,l[1000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i>=2) l[i]=a[i]-a[i-1];
		if(i==2) k=a[i]-a[i-1];
		if(i>2&&l[i]==k) sum++;
	}
	if(sum==n-2)
	{
		for(int i=n;i>=1;i--)
		{
			if(m>=(k*i*(i-1)/2))
			{
				cout<<i;
				return 0;
			}
		}
	}
}
