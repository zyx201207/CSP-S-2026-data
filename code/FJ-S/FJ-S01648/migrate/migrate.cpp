#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define st first
#define nd second
const int N = 5e3 + 5;

int c, t, n, d, x[N];
int p1[N], p2[N];

/*
bool chk1(int l, int r)
{
	int last = l, sum = 0, c1 = 0, c2 = 0;
	memset(p1, 0, sizeof(p1)); memset(p2, 0, sizeof(p2));
	p1[++c1] = l, p2[++c2] = r;
	for(int i = l; i <= r; )
	{
		while(sum + x[i] - x[last] <= d && i <= r)
			sum += (x[i] - x[last]), i++;
		if(i >= r) { p1[++c1] = r; break; }
		else p1[++c1] = i, sum = 0, last = i;
	}
	last = r, sum = 0;
	for(int i = r; i >= l; )
	{
		while(sum + x[last] - x[i] <= d && i >= l)
			sum += x[last] - x[i], i--;
		if(i <= l) { p2[++c2] = l; break; }
		else p2[++c2] = i, sum = 0, last = i;
	}
	//for(int i = 1; i <= c1; i++) cout << p1[i] << " \n"[i == c1];
	//for(int i = 1; i <= c2; i++) cout << p2[i] << " \n"[i == c2];
	if(c1 != c2) return false;
	for(int i = 1; i <= c1; i++)
		if(p1[i] != p2[c2 - i + 1]) return true;
	return false;
}
*/

bool chk(int s, int t)
{
	int c1 = 0, sum = 0, last = s;
	memset(p1, 0, sizeof(p1)); p1[++c1] = s;
	for(int i = s; i <= t; )
	{
		while(sum + x[i] - x[last] <= d && i <= t)
			sum += (x[i] - x[last]), i++;
		if(i >= t) { p1[++c1] = t; break; }
		else p1[++c1] = i, sum = 0, last = i;
	}
	//for(int i = 1; i <= c1; i++) cout << p1[i] << " \n"[i == c1];
	//cout << s << " " << t << " " << c1 << endl << endl;
	queue<pii> q; q.push({s, 1});
	int cnt = 0;
	while(!q.empty())
	{
		pii u = q.front(); q.pop();
		if(u.st >= t)
		{
			if(u.st == t && u.nd == c1) cnt++;
			continue;
		}
		if(u.nd >= c1) continue;
		for(int i = u.st + 1; i <= t; i++)
			if(x[i] - x[u.st] <= d) q.push({i, u.nd + 1});
	}
	return (cnt == 2);
}

void solve()
{
	cin >> n >> d; int ans = 0;
	for(int i = 1; i <= n; i++) cin >> x[i];
	sort(x + 1, x + n + 1);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			ans += chk(i, j);
	cout << ans << endl;
	return;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}













