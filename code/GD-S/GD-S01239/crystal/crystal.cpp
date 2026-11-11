#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=1;
	long long a[100005],b[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	sort(a,a+n);
	long long k;
	if(n%2==1)
	{
		k=(n+1)/2;
	}
	else
	{
		k=n/2;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=abs(a[k]-a[i]);
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(b[i]<b[j])
			{
				swap(b[i],b[j]);
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(m>=b[i])
		{
			m-=b[i];
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
