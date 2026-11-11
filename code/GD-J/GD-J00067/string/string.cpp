#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int n, num;
char tgt;
string a, b;
long long ans, p;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	for (int i = 1;i <= n;i++)
	{
		cin >> num >> tgt;
		
		for (int j = 1;j <= num;j++)
		{
			a[p] = tgt;
			p++;
		}
	}
	
	for (int i = 0;i < p;i++)
	{
		b[i] = a[p - i - 1];
	}
	
	for (int i = 0;i <= (p - 1) / 2;i++)
	{
		//cout << a[i] << " " << b[i] << endl;
		if (a[i] != b[i]) ans++;
	}
	
	cout << ans;
	
	return 0;
}
