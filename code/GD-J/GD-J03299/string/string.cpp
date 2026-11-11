#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
string c[200005];
bool hw()
{
	int ans1 = 0, ans2 = 0;
	string x[200005], y[200005];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= a[i]; j++)
		{
			x[i] = c[i];
		}
	}
	for(int i = n; i >= 1; i--)
	{
		for(int j = 1; j <= a[i]; j++)
		{
			y[i] = c[i];
		}
	}
	if(x == y)
		return true;
	else
		return false;
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	if(hw())
		cout << 0;
	return 0;
}
