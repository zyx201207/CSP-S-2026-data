#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500006],sum[300005],b[500006];
int main ()
{
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin >> n>> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] ;
	}
	int k;
	for (int i=1;i<=n;i++)
	{
		for (int k=1;k<=m;k++)
		{
			b[a[k]]=0;
		}
		for (int j=i;j<=n;j++)
		{
			if (b[a[j]]==0)
			{
				b[a[j]]=a[j];
			}
			else
			{
				for (int k=j-1;a[k]!=a[j];k--)
				{
					b[a[k]]=0;
				}
				b[a[k]]=0;
				b[a[j]]=a[j];
			}
		}
		for (int j=1;j<=m;j++)
		{
			if (b[j]!=0)
			{
				sum[b[j]]++;
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout << sum[i] << ' ';
	 } 
	return 0;
}
