#include <bits/stdc++.h>
#define N 200010
using namespace std;
using ll = long long;
struct node 
{
	ll num;
	char c;
}a[N];
struct yiz
{
	ll num;
	char a,b;
};
int n,pos = 1;
ll ans,pre[N];
vector<yiz> v;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;++i)
	{
		cin >> a[i].num >> a[i].c;
		pre[i] = pre[i - 1] + a[i].num;
	}
	ll mi = (pre[n] + 1) / 2;
	for (int i = 1;i <= n;++i)
	{
		if (mi <= pre[i])
		{
			pos = i;
			break;
		}
	}
	for (int i = n;i > pos;--i) a[i + 2] = a[i];
	a[pos + 1] = {1,a[pos].c};
	a[pos + 2] = {mi - 1 - (pre[n] - pre[pos]),a[pos].c};
	a[pos] = {a[pos].num - 1 - a[pos + 2].num,a[pos].c};
	n += 2;
	++pos;
//	for (int i = 1;i <= n;++i) cout << a[i].num << " " << a[i].c << endl;
	for (int i = 1;i <= n;++i) pre[i] = pre[i - 1] + a[i].num;
	int l = pos - 1,r = pos + 1;
	while (!(l < 0 || r > n + 1))
	{
		if (!a[l].num) --l;
		if (!a[r].num) ++r;
		int minn = min(a[l].num,a[r].num);
		v.push_back({minn,a[l].c,a[r].c});
		a[l].num -= minn;
		a[r].num -= minn;
	}
	for (auto t : v)
		if (t.a != t.b) ans += t.num;
	cout << ans;
	return 0;
}
