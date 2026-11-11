#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a;
char c;
string s;
int L;
int ans;

signed main()
{
	freopen("string.in" ,"r" ,stdin);
	freopen("string.out" ,"w" ,stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> c;
		L += a;
		for (int i = 1; i <= a; i++) s += c;
	}
	int l = 0 ,r = L - 1;
	while (l <= r)
	{
		if (s[l] != s[r])
		{
			ans++;
		}
		l++ ,r--;
	}
	cout << ans;
	
	return 0;
}
