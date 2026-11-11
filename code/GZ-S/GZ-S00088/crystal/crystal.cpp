#include <iostream> //CZ-S00088邓林轩
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[100000],num=0,c=0,sum=0;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if (n%2==0)
	{
		c+=a[n/2];
	}
	else
	{
		c+=a[(n+1)/2];
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]<c)
		{
			num+=c-a[i];
			a[i]=c;
		}
		else
		{
			continue;
		}
	}
	if (num==m)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]==c)
			{
				sum++;
			}
		}
		cout << sum;
	}
}
