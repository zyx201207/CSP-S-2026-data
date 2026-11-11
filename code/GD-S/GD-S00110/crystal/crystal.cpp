#include<bits/stdc++.h> 
using namespace std;
long long a[500050];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m, cnt = 1;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(long long i = 2; i <= n; i++)
	{
		if(m - (a[i] * (i - 1) - a[i - 1] * (i - 1)) >= 0) 
		{
			m = m - (a[i] * (i - 1) - a[i - 1] * (i - 1));
			cnt++;
		}
		else
		{
			break;
		}
	}
	cout << cnt;
	return 0;
}
