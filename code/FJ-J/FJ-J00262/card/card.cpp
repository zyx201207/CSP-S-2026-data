#include <bits/stdc++.h>
using namespace std;
int n,m,num[500005],ans[500005],last[500005];
bool vis[500005];
stack <int> s;
long long read()
{
	char c = getchar();
	long long res = 0,x = 1;
	while (c < '0' || c > '9')
	{
		if (c == '-')
		{
			x = -1;	
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * x;
} 
void wr(long long x)
{
	if (x >= 10)
	{
		wr(x / 10);	
	}
	putchar(x % 10 + '0');
	return ;
}
void write(long long x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}	
	wr(x);
	return ;
} 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		num[i] = read();
	}
	for (int i = 1;i <= n;i++)
	{
		memset(last,0,sizeof(last));
		memset(vis,0,sizeof(vis));
		for (int j = i;j <= n;j++)
		{
			if (last[num[j]])
			{
				while (num[s.top()] != num[i])
				{
					s.pop();
				}
				s.pop();
			}
			s.push(j);
			last[num[j]] = j;
		}
		while (!s.empty())
		{
			if (!vis[num[s.top()]])
			{
				ans[num[s.top()]]++;
				vis[num[s.top()]] = 1;
			}
			s.pop();
		}
	}
	for (int i = 1;i <= m;i++)
	{
		wr(ans[i]);
		putchar(' ');
	}
	return 0;
}
