//GZ-S00247 遵义市第四中学 翁铭卓 
#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 2e6 + 10;

int c, t;
int n, d;
int x[N];

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

bool check(int i)
{
	if (x[i + 3] - x[i + 1] <= d && x[i + 1] - x[i] <= d && x[i + 2] - x[i] <= d && x[i + 3] - x[i + 2] <= d && x[i + 3] - x[i] > d)
		return true;
	return false;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	read(c), read(t);
	
	while(t -- )
	{
		read(n), read(d);
		for (int i = 1; i <= n; i ++ )
			read(x[i]);
		
		int dd = x[2] - x[1];
		bool st = true;
		for (int i = 3; i <= n; i ++ )
			if (x[i] - x[i - 1] != dd)
				st = false;
				
		int cnt = 0;
		if (st)
		{
			if (dd >= d)
				cnt = 0;
			if (d > dd && d < 2 * dd)
				cnt = n - 2;
			if (d >= 2 * dd && d < 3 * dd)
				cnt = 2 * n - 5;
			else cnt = n - 2;
		}
		else
		{
			for (int i = 1; i <= n - 3; i ++ )
				if (check(i))
					cnt ++;
		}
		write(cnt), puts("");
	}
	
	return 0;
}
