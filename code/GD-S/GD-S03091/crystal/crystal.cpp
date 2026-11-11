#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b,c,d;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		b+=a[i];
	}
	sort(a+1,a+1+n);
	b/=n;
	for (int i=1;i<=n;i++)
	{
		if (a[i]<=b)
		{
			c++;
		}
	}
	cout << c << endl;
	return 0;
} 
