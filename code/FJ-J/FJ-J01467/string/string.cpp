#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node
{
	long long x;
	char c;
}g[N];
long long n, ans, p = 1;
string a;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> g[i].x >> g[i].c;
		for(int j = 1; j <= g[i].x; j++)
			a += g[i].c;	
	}
	long long len = a.size();
	a = " " + a;
	for(int i = 1; i <= len / 2; i++)
	{
		if(a[i] != a[len - i + 1])
			ans++;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
