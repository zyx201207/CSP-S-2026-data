#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n , m, a[100001], b[1000001];
	cin >> n >> m;
	set<int> s;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	} 
	for (int i = 0 ; i < n ; i++)
	{
	 	for (int j = i + 1 ; j <= n ; j++)
		{
		    b[s[j]]++;
		} 
	} 
	for (int i = 1 ; i <= m ; i++)
	{
		cout << b[i];
	} 
	return 0;
 } 
