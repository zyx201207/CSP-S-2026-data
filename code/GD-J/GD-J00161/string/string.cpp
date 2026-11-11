#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define ll long long
int n;
ll a[N], len, ans;
char c[N];
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i] >> c[i];
		len += a[i];
		for(int j = 1 ; j <= a[i]; j++) s += c[i];
	}
	s = " " + s;
	for(int i = 1; i * 2 <= len; i++)
	{
		if(s[i] != s[len - i + 1]) ans++;
	}
	cout << ans << "\n";
	return 0;
}
