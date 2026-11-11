#include <bits/stdc++.h>
using namespace std;

int n;
long long nu[200005];
char s[200005];
long long ans;

int main()
{
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i ++) cin >> nu[i] >> s[i];
	int h = 1,t = n;
	while (h < t)
	{
		if (nu[h] > nu[t])
		{
			nu[h] -= nu[t];
			if (s[h] != s[t]) ans += nu[t];
			t --;
		}else
		{
			nu[t] -= nu[h];
			if (s[h] != s[t]) ans += nu[h];
			h ++;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
