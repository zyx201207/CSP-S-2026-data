#include <iostream>
using namespace std;
int m,n;
long long a[212345];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >>m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if (m==1)
	{
		long long maxx=-1;
		for (int i=1;i<=n;i++)
		{
			if ((a[i]&a[i])>maxx)maxx=a[i]&a[i];
		}
		cout <<maxx;
	}
	else if(m==2)
	{
		long long maxx=-1;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if ((a[i]&a[j])>maxx)maxx=a[i]&a[j];
			}
		}
		cout <<maxx;
	}
	else if(m==3)
	{
		long long maxx=-1;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				for (int k=j+1;k<=n;k++)if ((a[i]&a[j]&a[k])>maxx)maxx=(a[i]&a[j]&a[k]);
			}
		}
		cout <<maxx;
	}
	return 0;
}
