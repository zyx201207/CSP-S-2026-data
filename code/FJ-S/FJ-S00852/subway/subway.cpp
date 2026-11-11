#include<bits/stdc++.h>
using namespace std;
#define N 505
#define M 500005
#define D 25
typedef long long ll;
#define fr(a, b, c) for(ll a = b; a <= c; a++)
#define relx(a, b) (a) = max(a, b)
#define reln(a, b) (a) = min(a, b)
#define mem(a, b) memset(a, b, sizeof(a))
const ll inf = 1ll<<61;
struct node
{
	ll t, l;
}b[M][D];
ll lk[M], w[M];
ll f[N][N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	mem(f, 0x3f);
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	ll x, y, k;
	fr(i, 1, m)
	{
		cin >> w[i];
	}
	fr(i, 1, n)
	{
		cin >> k;
		fr(j, 1, k)
		{
			cin >> x >> y;
			++lk[x];
			b[x][lk[x]].t = i;
			b[x][lk[x]].l = y;
		}
	}
	fr(i, 1, m)
	{
		for(ll k1 = 1; k1 <= lk[i]; k1++)
		{
			for(ll k2 = 1; k2 <= lk[i]; k2++)
			{
//				if(k1 == k2)continue;
				x = b[i][k1].t, y = b[i][k2].t;
				reln(f[x][y], b[i][k1].l + b[i][k2].l);
				f[y][x] = f[x][y];
			}
		}
	}
	fr(i, 1, n) f[i][i] = 0;
	fr(k, 1, n)
	{
		fr(i, 1, n)
		{
//			if(k == i)continue;
			fr(j, 1, n)
			{
				reln(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	ll ans;
	while(q--)
	{
		cin >> x >> y;
		ans = inf;
		for(ll k1 = 1; k1 <= lk[x]; k1++)
		{
			for(ll k2 = 1; k2 <= lk[y]; k2++)
			{
				reln(ans, f[b[x][k1].t][b[y][k2].t] + b[x][k1].l + b[y][k2].l);
			}
		}
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
	return 0;
}
//fc subway.out subway.ans
