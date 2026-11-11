#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i,j,m,n;
	long long mx=-1;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	long long sum=0;
	if(m==1)
	{
		cout<<mx;
	}
	else if(m==n)
	{
		for(i=2;i<=n;i++)
		sum=a[i]&a[i-1];
		cout<<sum;
	}
	else if(m==2)
	{
		mx=-1;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				mx=max(a[i]&a[j],mx);
			}
		}
		cout<<mx;
	}
	return 0;
}
