#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long a[1000000000000000005];
	for (int i = 0;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	long long milo = a[2]-a[1];
	long long sum = 0;
	while(m>=0)
	{
		m-=milo;
		milo+=milo;
		sum++;
	}
	return 0;
}
