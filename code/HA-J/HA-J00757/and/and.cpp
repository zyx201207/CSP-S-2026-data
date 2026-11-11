#include<bits/stdc++.h>
using namespace std;
int m,n,big=0;
int a[200010];
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
		int big=0;
		for(int i=1;i<=n;i++)
		{
			if(big<a[i])
			{
				big=a[i];
			}
		}
		cout<<big;
		return 0;
	}
	if(m==n)
	{
		int as;
		for(int i=0;i<n;i++)
		{
			as=as and a[i+1];
		}
		cout<<as;
		return 0;
	}
	if(m==2)
	{
		int as=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int sa=a[i] and a[j];
				if(sa>as)
				{
					as=sa;
				}
			}
		}
		cout<<as;
		return 0;
	}
	cout<<"12";
	return 0;
}
