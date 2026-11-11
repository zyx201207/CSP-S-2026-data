#include <iostream>
using namespace std;
int maxx[15],maxxx=0,f=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin >> n >> m ;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
    }
    if (m==n)
    {
		f=a[1];
		for (int i=2;i<=n;i++)
		{
			f=a[i] & f;
		}
		cout << f ;
	}
	if (m==(n-1))
	{
		f=a[1];
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (j!=i)
				{
					f=f & a[j];
				}
			}
		}
		cout << f ;
	}
	if (m==1)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]>f)
			{
				f=a[i];
			}
		}
		cout << f ;
	}
	if (m==2)
	{
	    for (int i=1;i<=n;i++)
	    {
		    for (int j=1;j<=n;j++)
			{
				if (i!=j)
				{
					if ((a[i] & a[j])>maxxx)
					{
						maxxx=a[i] & a[j];
					}
				}
			}
		}
		cout << maxxx ;
	}
	return 0;
}
