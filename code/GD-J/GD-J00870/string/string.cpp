#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n, siz, l, r, cnt;
string s;
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int num;
		char c;
		cin >> num >> c;
		while(num--) s += c;
	}
	siz = s.size();
	if(s.size() % 2 == 0) l = siz / 2, r = siz / 2 + 1;
	else l = r = siz / 2;
	while(l <= r && l >= 0 && r <= siz)
	{
		l--, r++;
		if(s[l] != s[r]) cnt++;
	}
	cout << cnt;
	return 0;
}

