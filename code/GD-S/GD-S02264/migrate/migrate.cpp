#include <bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005]={0};

void op()
{
	long long n,d;
	cin >> n >> d;
	long long qw=0,l=0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(long long u = 1;u <= n;u++)
	{
		if(u+3 > n) break;
		l=0;
		long long v = u+3;
		if(a[v] - a[u+1] == d)
		{
			l++;
		}
		if(a[v-1] - a[u] == d)
		{
			l++;
		}
		if(l == 2)
		{
			qw++;
		}
	}
	cout << qw << endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 1;i <= t;i++)
	{
		op();
	}
	return 0;
}
