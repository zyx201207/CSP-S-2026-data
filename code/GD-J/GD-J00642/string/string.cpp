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
char getch()
{
	char ch = getchar();
	for (ch;ch <= ' ';ch = getchar());
	return ch;
}
const int N = 2e5 + 5;
int n;
struct Node
{
	int cnt;
	char ch;
} q[N];
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	n = read();
	for (int i = 1;i <= n;i++)
	{
		int a = read();
		char c = getch();
		q[i] = {a, c};
	}
	int head = 1, tail = n, ans = 0;
	while (head < tail)
	{
		auto &lef = q[head], &rig = q[tail];
		int len = min(lef.cnt, rig.cnt);
		if (lef.ch != rig.ch) ans += len;
//		if (lef.ch !=rig.ch) cout<<len<<" : ", endl;
//		cout<<"head : "<<lef.ch<<" , "<<lef.cnt, endl;
//		cout<<"tail : "<<rig.ch<<" , "<<rig.cnt, endl;
//		endl;
		lef.cnt -= len, rig.cnt -= len;
		if (!lef.cnt) head++;
		if (!rig.cnt) tail--;
	}
	write(ans);
	return 0;
}

