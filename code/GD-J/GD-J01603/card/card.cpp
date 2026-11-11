#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read();
const int N = 5e5 + 10;
int a[N], ans[N], pl[N], st[N];
int tot = 0;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	/*for(int k = 1; k <= n; k++)
	{
		tot = 0;
		for(int i = k; i <= n; i++)
		{
			if(pl[a[i]])
			{
				for(int j = pl[a[i]] + 1; j <= tot; j++) pl[a[j]] = 0;
				tot = pl[a[i]];
			}
			else
			{
				st[++tot] = a[i];
				pl[a[i]] = tot;
			}
		}
		for(int i = 1; i <= m; i++)
		{
			//printf("%d ", pl[i]);
			if(pl[i])
			{
				ans[i]++;
				pl[i] = 0;
			}
		}
		for(int j = 1; j <= tot; j++)
		{
			ans[st[j]]++;
			pl[st[j]] = 0;
			//printf("%d ", st[j]);
		}
		//printf("\n");
	}*/
	reverse(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		if(pl[a[i]])
		{
			for(int j = pl[a[i]] + 1; j <= tot; j++) pl[st[j]] = 0;
			tot = pl[a[i]];
		}
		else
		{
			st[++tot] = a[i];
			pl[a[i]] = tot;
		}
		for(int j = 1; j <= tot; j++)
		{
			ans[st[j]]++;
			//printf("%d ", st[j]);
		}
		//printf("\n");
	}
	for(int i = 1; i <= m; i++)
	{
		printf("%d ", ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 3
1 2 1 3
ans:3 1 4

10 3
3 1 2 1 3 2 3 1 2 1
ans:10 3 3
*/

inline ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
