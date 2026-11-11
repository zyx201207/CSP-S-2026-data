#include <bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[500005];
long long int b[500005];
long long int ans[500005];
long long int num = 0;
long long int sum = 0;
long long int man = 0;
long long int op = 2;
long long int v = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 2;i <= n;i++)
	{
		b[i] = a[i] - a[i-1];
		b[i] = abs(b[i]);
	}
	for(int i = n;i >= 1;i--)
	{
		ans[i] = ans[i + 1] + b[i];
	}
	for(int i = 2;i <= n;i++)
	{
		if (sum + (i - 1 - v) * b[i] > m)
		{
			sum -= ans[i-op+1];
			num--;
			op++;
			v++;
			man = max(man,num);
		}
		else
		{
			sum += (i - 1 - v) * b[i];
			num++;
			man = max(man,num);
		}
	}
	cout << ++man;
}
