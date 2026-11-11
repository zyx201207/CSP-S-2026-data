#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum=0,maxx=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	sum=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		sum=sum&a[i];
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	else if(m==n)
	{
		cout<<sum;
		return 0;
	}
	else if(m==2)
	{
		int maxa=-1;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int b=a[i];
				b=b&a[j];
				maxa=max(maxa,b);
			}
		}
		cout<<maxa;
		return 0;
	}
	return 0;
}
