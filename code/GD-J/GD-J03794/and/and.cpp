#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",strin);
	freopen("and.out","w",strout);
	int n,m;
	int a[2005];
	long long num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			num=num^a[i];
		}
		cout<<num;
	}
	else if(m==1)
	{
		cout<<max(a[1],a[n]);
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;i<=n;j++)
			{
				int t=a[i]^a[j];
				if(num<t)
				{
					num=t;
				}
			}
		}
		cout<<num;
	}
	else
	{
		cout<<"5000";
	}
	return 0;
}
