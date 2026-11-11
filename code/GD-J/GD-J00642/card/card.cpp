#include <bits/stdc++.h>
#define int long long
#define eb emplace_back
#define endl putchar('\n')
using namespace std;
int read()
{
	int sum = 0, f = 1;
	char ch = getchar();
	for (ch;ch < '0' || ch > '9';ch = getchar()) if (ch == '-') {f = -1;}
	for (ch;ch >= '0' && ch <= '9';ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * f;
}
void write(int x)
{
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], ans[M];
int lst[N], nxt[N], pos[M];
vector<int> sta;
bool insta[N];
void getans(int now)
{
	while (now <= n)
	{
		now = pos[a[now]];
		ans[a[now]]++;
		now++;
	}
}
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1;i <= n;i++)
	{
		a[i] = read();
		lst[i] = pos[a[i]];
		nxt[lst[i]] = i;
		pos[a[i]] = i;
	}
	for (int i = 1;i <= n;i++) getans(i);
	for (int i = 1;i <= m;i++) write(ans[i]), putchar(' ');
	return 0;
}

