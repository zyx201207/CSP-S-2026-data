#include <bits/stdc++.h>
using namespace std;

int sum = 0;

int main()
{
	freopen("string.in", "r",stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	long long a,m = 0LL; 
	char c;
	string h;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> c;
		for (int j = 0; j < a; j++)
			h += c;
		m += a;
	}
	
	for (int i = 0; i < m/2; i++)
	{
		int j = m - i - 1;
		if (h[i] != h[j])
			sum++;
	}
	
	cout << sum;
	return 0;
}
