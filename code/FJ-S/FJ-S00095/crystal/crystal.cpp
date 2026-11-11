#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int N = 500010;

int n, m;
int seq[N];

inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	
	return x * f;
}

inline void write(int x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
//	n = read(), m = read();
	for (int i = 1; i <= n; ++ i )
	{
		cin >> seq[i];
//		seq[i] = read();
	}
	
	sort(seq + 1, seq + 1 + n); 
	
	int res = 0, cur = 0;
	for (int i = 1, j = 0; i <= n; ++ i )
	{
		while (j < n && cur + (seq[j + 1] - seq[j]) * (j - i + 1) <= m)
			j ++ , cur += (seq[j] - seq[j - 1]) * (j - i);
//		cout << i << " " << j << " " << cur << "\n";
		res = max(res, j - i + 1);
		cur -= seq[j] - seq[i];
	}
	
	cout << res << endl;
//write(res);
	
	return 0;
}

/*
hui mie le
100+100+[40,48]+?=[240,248]
bi J zu jiu di le [20,28] fen, kan lai shang wu zhen de shi zai zan RP.
1= shi you le
dan shi bu neng qu gong da ce suo le
zhen ke xi
T3 te shu xing zhi gan jue hui zha
T4 te shu xing zhi he bao li lai bu ji da le
T1 T2 T3 T4 bu ke neng bu ke neng hui gua fen!!!
wo men NOI Plus jian
zhun bei fu jian whk le
12 days hou hui gui.
bye.
*/
