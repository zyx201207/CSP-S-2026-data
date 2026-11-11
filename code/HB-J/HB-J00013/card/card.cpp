#include <bits/stdc++.h>
using namespace std;
const int N = 500005, M = 300005;
bool book[M];
int  a[N], ans[M];
inline int read()
{
	char x = getchar_unlocked();
	int res = 0;
	while (x > '9' || x < '0') x = getchar_unlocked();
	while (x >= '0' && x <='9')
	{
		(res *= 10) += (x - '0');
		x = getchar_unlocked();
	}
	return res;
}
int main()
{
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
	{
		stack <int> cards;
		memset (book, false, sizeof(book));
		for (int j = i; j <= n; j++)
		{
			if (book[a[j]])
			{
				while (cards.top() != a[j])
				{
					book[cards.top()] = false;
					cards.pop();
				}
				cards.pop();
			}
			cards.push(a[j]);
			book[a[j]] = true;
		}
		while (!cards.empty())
		{
			ans[cards.top()]++;
			cards.pop();
		}
	}
	for (int i = 1; i < m; i++) printf("%d ", ans[i]);
	printf("%d\n", ans[m]);
	return 0;
}
/*
Trick||Treat!
Trick or Treat!
~~I remembered one thing...~~
# Today is Hallowing!!!
So why nobody make a "Strange Actions"（“迷惑行为大赏”） for HuBei Province?
My luogu id:1876559, name:yghdby
now:100 + 0 + 25 + 48 = 173 pts(at 09:45)
now:100 + 50 + 25 + 48 = 223 pts(at 10:04)
By the way:who used vi or vim as me, as well?
I love read()ing!!!
什么？你问我哪里来的中文输入法？
设置里调的。。。
\bx\bx\bx
*/
