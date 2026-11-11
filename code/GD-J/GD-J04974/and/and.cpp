#include<bits/stdc++.h>
using namespace std;
int a[200005]={0};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum,oo=0,o1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		oo=max(oo,a[i]);
	}
	if(n==m)
	{
		sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==1)
	{
		cout<<oo;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;i++)
		{
			if(a[j]>oo)
			{
				oo=a[j];
				o1=j;
			}
		}
		if(sum==0)
		sum=oo;
		else
		sum=sum&oo;
		a[o1]=0;
		oo=0;
	}
	cout<<sum;
}
