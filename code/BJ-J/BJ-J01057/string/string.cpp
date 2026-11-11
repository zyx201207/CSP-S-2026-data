#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct info
{
	int size;
	char ch;
} s[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> s[i].size >> s[i].ch;
		
	int l = 1, r = n;
	long long ans = 0;
	while (l < r)
	{
		int lsz = s[l].size, rsz = s[r].size;
		if (s[l].ch != s[r].ch)
		{
			ans += min(lsz, rsz);
			if (lsz > rsz) s[l].size -= s[r].size;
			else if (lsz < rsz) s[r].size -= s[l].size;
		}
		
		if (lsz >= rsz) r--;
		if (lsz <= rsz) l++;
	}
	
	cout << ans;
	
	return 0;
}