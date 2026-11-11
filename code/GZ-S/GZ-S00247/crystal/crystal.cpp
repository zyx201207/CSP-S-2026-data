//GZ-S00247 遵义市第四中学 翁铭卓 
#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 5e5 + 10;

int n, m;
ll a[N], pre[N];

template<typename T> inline void read(T &qwq)
{
	T x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (isdigit(ch))
		x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	qwq = x * f;
	return;
}

template<typename T> inline void write(T x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	read(n), read(m);
	for (int i = 1; i <= n; i ++ )
		read(a[i]);
		
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; i ++ )
		pre[i] = pre[i - 1] + a[i];
	int l = 1, r = 1, ans = 1;
	while (r <= n)
	{
		if ((ll)(r - l + 1) * a[r] - pre[r] + pre[l - 1] <= m)
			ans = max(r - l + 1, ans), r ++ ;
		else l ++ ;
	}
	
	write(ans);
	
	return 0;
}
