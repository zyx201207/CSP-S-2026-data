#include <bits/stdc++.h>
using namespace std;
long long a[10010] = {0};
long long b[10010] = {0};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			cnt++;
			b[cnt] = a[i] && a[j];
		}
	}
	int maxn = 0;
	for(int i = 1;i <= cnt;i++)
	{
		if(maxn < b[i])
		{
			maxn = b[i];
		}
	}
	cout << a[n];
}
