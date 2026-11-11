#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool cmp(unsigned int a, unsigned int b)
{
	return a > b;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	unsigned int n, m;
	cin >> n >> m;
	vector<unsigned int> a(n);
	for (unsigned int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end(), cmp);
	unsigned int num = a[0];
	for (unsigned int i = 1; i < m; i++)
	{
		num &= a[i];
	}
	cout << num << '\n';
	
	return 0;
}
