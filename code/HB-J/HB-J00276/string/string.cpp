#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, a[N], x, ans;
char ch[N], ch1[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> ch[i];
		x += a[i];
		for(int j = x - a[i]; j <= x; j++) ch1[j] = ch[i];
	}
	for(int i = 1; i <= x / 2; i++)
	{
		if(ch1[i] != ch1[x - i + 1]) ans++;
	}
	cout << ans;
	return 0;
}
