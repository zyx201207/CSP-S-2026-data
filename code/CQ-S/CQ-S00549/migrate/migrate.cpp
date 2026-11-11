#include <bits/stdc++.h>
#define int long long
#define pair<int, int> PII;

using namespace std;

bool BEGIN;

namespace FIO
{
	char buf[1 << 22], *p1, *p2;
	char c;
	int f;
	#define gc() ((p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin)), *p1 ++)

	void read(int &res)
	{
		res = 0;
		f = 1;
		c = gc();
		for(;!isdigit(c);c = gc()) if(c == '-') f = -1;
		for(;isdigit(c);c = gc()) res = (res << 3) + (res << 1) + (c & 15);
		res = res * f;
	}
}

int c, t;
int n, d;
int a[2000010];
int nxt[2000010], pre[2000010];
int ans;

bool END;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	cerr << "memory: " << (int)(&BEGIN - &END) << "\n";
	cin >> c >> t;
	while(t --)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i ++) cin >> a[i], pre[i] = 1e18;;
		for(int i = 1, j = 1;i <= n;i ++)
		{
			while(j < n && a[j + 1] - a[i] <= d) j ++;
			nxt[i] = j;
			pre[j] = min(pre[j], i);
		}
		for(int i = 1;i <= n;i ++)
		{
			for(int j = i;j <= n;j ++)
			{
				int ok = 0;
				for(int k = i;k < j;)
				{
					cerr << k << "\n";
					if(nxt[nxt[k]] <= j)
					{
						int x = nxt[nxt[k]];
						if(pre[pre[x]] == k && nxt[k] - 1 == pre[x]) ok ++;
						if(ok > 1) break;
						k = nxt[nxt[k]];
					}
					else k = nxt[k];
				}
				if(ok == 1) ans ++;
			}
		}
		cout << ans;
	}
	return 0;
}
/*
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956

b + 1 = c
pre[d] = b
nxt[a] = c

pre[d] + 1 = nxt[a] = c
nxt[nxt[a]] = d
pre[pre[d]] = a

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
