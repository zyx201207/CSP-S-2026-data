#include <bits/stdc++.h>
using namespace std;
long long n,m,h = 0,d = 0;
long long a[500005];
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for (int i = 1;i <= n;i ++)
	{
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	int f = a[1];
	for (int i = 2;i <= n;i ++)
	{
		h += a[i]-f;
		if (h <= m || a[i] == a[i-1])
		{
			d ++;
		}
	}
	cout<<d+1<<endl;
	return 0;
}
