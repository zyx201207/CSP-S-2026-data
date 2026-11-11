#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n;
	int sum = 0;
	for (int i = 1 ; i <= n ; i++)
	{
	    int c;
		char ch;
		cin >> c >> ch;
		sum += c;
	}
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	if (sum % 2 == 0)
	{
		cout << 0;
		return 0;
	}	
	return 0;
 } 
