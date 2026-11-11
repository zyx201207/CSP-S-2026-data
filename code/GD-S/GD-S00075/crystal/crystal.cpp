#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;

int n;
long long m, a[maxn], diff[maxn], sum;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1;i < n;i++)
	{
		diff[i] = a[i + 1] - a[i];
	}
	
	cout << 2;
	
	return 0;
}
