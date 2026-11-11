#include <bits/stdc++.h>
#define int long long
#define N 5010
using namespace std;

bool appear[N], _appear[N];
int n, m;
int a[N];
int answer[N];
int s[N], top = 0;

void game(int start)
{
	memset(appear, false, sizeof appear);
	memset(_appear, false, sizeof _appear);
	memset(s, 0, sizeof s);
	top = start - 1;
	for (int i = start; i <= n; i++)
	{
		if (appear[a[i]])
		{
			for (int x = start; x <= top; x++)
				if (s[x] == a[i])
				{
					for (int j = x; j <= top; j++)
						appear[s[j]] = false;
					top = x - 1;
					break;
				}
		}
		appear[a[i]] = true;
		s[++top] = a[i];
	}
	for (int i = start; i <= top; i++)
	{
		if (!_appear[s[i]])
		{
			appear[s[i]] = true;
			answer[s[i]]++;
		}
	}
}


signed main()
{
	freopen("card.in",  "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		game(i);
	for (int i = 1; i <= m; i++)
		cout << answer[i] << ' ';
	return 0;
}
