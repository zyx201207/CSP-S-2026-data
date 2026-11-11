#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 1e6 + 5;
int a[N], front[N], behind[N];
char s[N], fronts[N], behinds[N];
int frontLen = 1, behindLen = 1;

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int n, sum = 0; cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> s[i], sum += a[i];
	int half = sum / 2,  cnt = 0, i = 1;
	for (; cnt < half; ++i) cnt += a[i], front[frontLen] = a[i], fronts[frontLen] = s[i], frontLen++;
	--frontLen;
	
	bool flag = true;
	if (cnt > half)
	{
		front[frontLen] = a[frontLen] - (cnt - half);
		if (sum & 1)
		{
			if (cnt - half - 1 != 0)
			{
				behind[behindLen] = cnt - half - 1;
				behinds[behindLen] = s[frontLen];
				behindLen++;
			} else flag = false;
		}
		else
		{
			behind[behindLen] = cnt - half;
			behinds[behindLen] = s[frontLen];
			behindLen++;
		}
	}
	
	int tmp = i;
	for (; i <= n; ++i)
		if (i == tmp && sum & 1 && flag) behind[behindLen] = a[i] - 1, behinds[behindLen] = s[i], behindLen++;
		else behind[behindLen] = a[i], behinds[behindLen] = s[i], behindLen++;
	--behindLen;
	
	int index = 1, ans = 0;
	while (index != frontLen+1 || behindLen != 0)
	{
		if (fronts[index] == behinds[behindLen])
		{
			if (front[index] == behind[behindLen]) ++index, --behindLen;
			else if (front[index] < behind[behindLen]) behind[behindLen] -= front[index], ++index;
			else front[index] -= behind[behindLen], --behindLen;
		}
		else
		{
			if (front[index] == behind[behindLen]) ans += front[index], ++index, --behindLen;
			else if (front[index] < behind[behindLen]) ans += front[index], behind[behindLen] -= front[index], ++index;
			else ans += behind[behindLen], front[index] -= behind[behindLen], --behindLen;
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

