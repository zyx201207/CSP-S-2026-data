#include <bits/stdc++.h>
using namespace std;
int n;
long long int a[200005];
char c[200005];
long long int num = 0;
long long man = 0;
long long int ans = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		man += a[i];
	}
	int i = 1;
	int j = n;
	while(ans < man)
	{
		if (a[i] == 0)
		{
			i++;
		}
		if (a[j] == 0)
		{
			j--;
		}
		if (c[i] != c[j])
		{
			long long int sum = min(a[i], a[j]);
			a[i] -= sum;
			a[j] -= sum;
			num += sum;
			ans += 2 * sum;
		}
		if (c[i] == c[j])
		{
			long long int sum = min(a[i], a[j]);
			a[i] -= sum;
			a[j] -= sum;
			ans += 2 * sum;
		}
	}
	cout << num;
	return 0;
}
