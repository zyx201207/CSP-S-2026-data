#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,q[300000],w=1;
	long long a[200005];
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int s = -1,i1,j1;
	for (int i = 1;i <= n-1;i++)
	{
		for (int j = i+1;i <= n;i++)
		{
			if(s <= (a[j] & a[i]) && a[i]!=0 && a[j]!=0)
			{
				s = a[i] & a[j];
				i1 = i;
				j1 = j;
			}
		}
	}
	a[i1] = 0;
	a[j1] = 0;
	while (w!=m-1)
	{
		int p = -1;
		for (int i = 1;i <= n;i++)
		{
			if (p == -1)
			{
				p = s & a[i];
				i1 = i;
			}
			else
			{
				if(p < (p & a[i]))
				{
					p = p & a[i];
					i1 = i;
				}
			}
		}
		s = p;
		a[i1] = 0;
		w++;
	}
	cout << s;
}
