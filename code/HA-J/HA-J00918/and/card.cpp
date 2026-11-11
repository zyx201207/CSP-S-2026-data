#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n],q[n];
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int w=n;w>=1;w--)
	{
		for (int i=1;w<=n;i++)
	    {
			if (a[i]==a[i+1])
			{
				for (int i=n;i>=i+1;i--)
				{
					q[i]++;
				}
			}
	    }
	}
	for (int i=1;i<=m;i++)
	{
		cout<<q[i];
	}
	return 0;
}
