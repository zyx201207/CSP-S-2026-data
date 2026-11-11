#include <iostream>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=-1;
	if(m==1)
	{
		for(int i=1;i<=m;i++)
		{
			a[i]&=a[i];
			if(a[i]>x)
			{
				x==a[i];
			}
		}
		cout<<x;
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(x<(a[i]&a[j]))
				{
					x=a[i]&a[j];
				}
			}
		}
		cout<<x;
		return 0;
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j]>a[j+1])
				{
					int y=a[j];
					a[j]=a[j+1];
					a[j+1]=y;
				}
			}
		}
		if(n%2==1)
		{
			x=n%2+1;
		}
		else
		{
			x=n%2;
		}
		cout<<x;
		return 0;
	}
	return 0;
}
