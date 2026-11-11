#include<bits/stdc++.h>
#define twin pair<long long, char>

using namespace std;
const int N = 2e5+5;
struct String
{
	long long res;
	char c;
	int p;
};
int n;
long long ans = 0;
twin a[N];
String l, r;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	l = {a[1].first, a[1].second, 1}, r = {a[n].first, a[n].second, n};
	while(l.p<r.p)
	{
		if(l.c==r.c)
		{
			if(l.res==r.res)
			{
				l.p++, r.p--;
				l.res = a[l.p].first, l.c = a[l.p].second;
				r.res = a[r.p].first, r.c = a[r.p].second;
			}
			else if(l.res<r.res)
			{
				r.res -= l.res;
				l.p++;
				l.res = a[l.p].first, l.c = a[l.p].second;
			}
			else
			{
				l.res -= r.res;
				r.p--;
				r.res = a[r.p].first, r.c = a[r.p].second;
			}
		}
		else
		{
			if(l.res==r.res)
			{
				ans += r.res;
				l.p++, r.p--;
				l.res = a[l.p].first, l.c = a[l.p].second;
				r.res = a[r.p].first, r.c = a[r.p].second;
			}
			else if(l.res<r.res)
			{
				ans += l.res;
				r.res -= l.res;
				l.p++;
				l.res = a[l.p].first, l.c = a[l.p].second;
			}
			else
			{
				ans += r.res;
				l.res -= r.res;
				r.p--;
				r.res = a[r.p].first, r.c = a[r.p].second;
			}
		}
	}
	cout << ans;
		
	return 0;
}
