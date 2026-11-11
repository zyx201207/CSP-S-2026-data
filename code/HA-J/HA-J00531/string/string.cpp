#include <bits/stdc++.h>
using namespace std;
int n,a[10000001], c[1000001], cnt = 0;
queue<int> s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	if(n <= 1)
		cout << 0;
	return 0;
}
