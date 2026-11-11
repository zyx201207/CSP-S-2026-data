#include <bits/stdc++.h>
#define i64 long long
#define ull unsigned long long
#define AC return 0;
using namespace std;

inline void initbegin ()
{
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	return ;
}

const int N = 1919810, M = 5001;
const int inf = 0x3f3f3f3f, mod = 998244353;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {0, 0, 1, -1, 1, -1, -1, 1, 0};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1, 0};

int mian ()
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a != c)
	{
		cout << 0 << 0 << 0 << 0 << endl;
		AC
	}
	cout << 1;
	int aa = (b[0] - '0') * 10 + (b[1] - '0');
	int bb = (d[0] - '0') * 10 + (d[1] - '0');
	if (aa != bb)
	{
		cout << 0 << 0 << 0 << endl;
		AC
	}
	cout << 1;
	int cc = (b[2] - 'A' + 1), dd = (d[2] - 'A' + 1);
	bool flag1 = (cc == 6 && dd == 4);
	bool flag2 = (cc == 4 && dd == 6);
	bool flag3 = (cc == 1 && dd == 2);
	bool flag4 = (cc == 1 && dd == 3);
	bool flag5 = (cc == 2 && dd == 1);
	bool flag6 = (cc == 2 && dd == 3);
	bool flag7 = (cc == 3 && dd == 1);
	bool flag8 = (cc == 3 && dd == 2);
	if (!(flag1) && !(flag2) && !(flag3) && !(flag4) && !(flag5) && !(flag6) && !(flag7) && !(flag8))
	{
		cout << 0 << 0 << endl;
		AC
	}
	cout << 1;
	if (!(flag1) && !(flag2) && !(flag3) && !(flag5) && !(flag6) && !(flag8))
	{
		cout << 0 << endl;
		AC
	}
	cout << 1 << endl;
	AC
}

/*
task1
02 01A 02 01B

1111


task2
02 01C 02 01A

1110


task3
02 01C 02 01D

1100


task4
02 02B 02 01A

1000


task5
02 01A 03 01A

0000
*/

/*
all:
5
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A

1111
1110
1100
1000
0000
*/

signed main ()
{
    initbegin ();
    int t = 1;
//	cin >> t;
    while (t--)
    {
		mian ();
	}
	AC
}

