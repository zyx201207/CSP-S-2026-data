#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a.begin() + 1, a.begin() + n + 1);
	cout << a[n - m + 1];
}
