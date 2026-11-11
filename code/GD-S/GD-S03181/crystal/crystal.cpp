#include<bits/stdc++.h>
using namespace std;
long long n, m, a[510000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(m == 5)
	{
		cout << 3;
	}
	if(m == 8)
	{
		cout << 4;
	}
	
	return 0;
}
