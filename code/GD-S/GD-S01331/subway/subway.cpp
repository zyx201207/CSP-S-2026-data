#include <bits/stdc++.h>
#define ll long long
using namespace std;

int c,n,m,d,q;

struct node
{
	int a;
	ll b;
	int c;
}nus[4000002];
int nusl;
int nut[1000002];
ll vs[500002];

void add(int a,int b,ll c)
{
	nus[++ nusl] = {b,c,nut[a]};
	nut[a] = nusl;
}

struct point
{
	ll a;
	int b;
};

struct heap
{
	point que[2000002];
	int quel;
	void push(point x)
	{
		que[++ quel] = x;
		int a = quel;
		while (a > 1 && que[a].a < que[a >> 1].a)
		{
			swap(que[a],que[a >> 1]);
			a = a >> 1;
		}return ;
	}
	void pop()
	{
		que[1] = que[quel];
		quel --;
		int a = 1;
		while ((a << 1) <= quel && min(que[a << 1].a ,((a << 1) + 1 <= quel ? que[(a << 1) + 1].a : 1000000000000000000)) < que[a].a)
		{
			if (que[a << 1].a < que[(a << 1) + 1].a || (a << 1) + 1 > n)
			{
				swap(que[a << 1],que[a]);
				a <<= 1;
			}else
			{
				swap(que[(a << 1) + 1],que[a]);
				a = (a << 1) + 1;
			}
		}
		return ;
	}
}rt;

ll ans[1000002];
bitset<1000002> fg;
ll dijkstra(int s,int t)
{
	while (rt.quel) rt.pop();
	for (int i = 1;i <= m + n;i ++) 
	{
		ans[i] = 1000000000000000000;
		fg[i] = 0;
	}
	ans[s] = 0;
	rt.push({0,s});
	while (rt.quel)
	{
		point xx = rt.que[1];
		rt.pop();
		if (fg[xx.b]) continue;
		fg[xx.b] = 1;
		if (xx.b == t) return xx.a;
		for (int i = nut[xx.b];i;i = nus[i].c)
		{
			int son = nus[i].a;
			if (ans[son] > ans[xx.b] + nus[i].b && !fg[son])
			{
				ans[son] = ans[xx.b] + nus[i].b;
				rt.push({ans[son],son});
			}
		}
	}
	return -1;
}

point que[1000002];

ll bfs(int s,int t)
{
	int hs = 0,ts = 1;
	for (int i = 1;i <= m + n;i ++) 
	{
		ans[i] = 1000000000000000000;
		fg[i] = 0;
	}
	ans[s] = 0;
	que[1] = {0,s};
	fg[s] = 1;
	while (hs < ts)
	{
		hs ++;
		point xx = que[hs];
		if (xx.b == t) return xx.a;
		for (int i = nut[xx.b];i;i = nus[i].c)
		{
			int son = nus[i].a;
			if (!fg[son])
			{
				fg[son] = 1;
				que[++ t] = {ans[xx.b] + nus[i].b,son};
				if (son == t) return ans[xx.b] + nus[i].b;
			}
		}
	}
	return -1;
}

int main()
{
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i = 1;i <= m;i ++) scanf("%lld",&vs[i]);
	for (int i = 1;i <= n;i ++)
	{
		int k;
		scanf("%d",&k);
		for (int f = 1;f <= k;f ++)
		{
			int a;
			ll b;
			scanf("%d%lld",&a,&b);
			add(a,m + i,b);
			add(m + i,a,b);
		}
	}
	if (c >= 12 && c <= 19)
	{
		while (q --)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",bfs(l,r) + vs[l] + vs[r]);
		}
	}else
	{
		while (q --)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",dijkstra(l,r) + vs[l] + vs[r]);
		}
	}
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/

