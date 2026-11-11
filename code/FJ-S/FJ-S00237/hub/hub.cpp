#include <iostream>

using namespace std;

template <typename T>
inline void read(T &Fw)
{
	static char Fc;
	static int Fop;
	Fop = 1;
	Fw = 0;
	do {Fc = getchar();}while ((Fc < '0' || Fc > '9') && Fc != '-');
	if (Fc == '-') Fc = getchar(), Fop = -1;
	do {Fw = (Fw << 1) + (Fw << 3) + (Fc ^ 48), Fc = getchar();}while (Fc >= '0' && Fc <= '9');
	Fw *= Fop;
}

const int N = 1000010, M = 2000010;

int n, m;
int h[N], e[M], ne[M], idx;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

struct Work1
{
	int dep[N], root1, root2, st[N], Root, d[N];
	int dfs1(int u, int fa, int mid)
	{
		int res = mid;
		for (int i = h[u]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (j == fa || st[j]) continue;
			res = min(res, dfs1(j, u, mid));
			if (res == -1) return -1;
		}
		if (!res)
		{
			root1 = u;
			return -1;
		}
		return res - 1;
	}
	
	void dfs2(int u, int fa, int mid)
	{
		st[u] = 1;
		if (!mid) return ;
		for (int i = h[u]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (j == fa || st[j]) continue;
			dfs2(j, u, mid - 1);
		}
	}
	
	int check(int mid)
	{
		for (int i = 1; i <= n; ++ i) st[i] = 0;
		
		root1 = root2 = 0;
		dfs1(Root, 0, mid);
		if (!root1) return 1;
		dfs2(root1, 0, mid);
		
		root2 = root1, root1 = 0;
//		if (mid == 1)
//		{
//			cout << root2 << endl;
//			for (int i = 1; i <= n; ++i) cout << st[i] <<" ";
//			puts("");
//		}
//		if (mid == 1)
//		{
//			for (int i = 1; i <= n; ++i) cout << st[i] <<" ";
//			puts("");
//		}
		
		for (int i = h[root2]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (st[j]) continue;
			dfs1(root2, 0, mid);
			break;
		}
		if (!root1) return 1;
		dfs2(root1, 0, mid);
		
//		if (mid == 1)
//		{
//			puts("HAHA");
//		}
		int flag = 1;
		for (int i = 1; i <= n; ++ i)
		{
			if (!st[i]) flag = 0;
		}
		return flag;
	}
	
	void solve()
	{
		read(n), read(m);
		idx = 0;
		for (int i = 1; i <= n; ++ i) h[i] = -1;
		for (int i = 1, a, b; i < n; ++ i)
		{
			read(a), read(b);
			add(a, b), add(b, a), ++ d[a], ++ d[b];
		}
		for (int i = 1; i <= n; ++ i)
		{
			if (d[i] == 1)
			{
				Root = i;
				break;
			}
		}
		
		int l = 0, r = n - 1;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", r);
	}
}work1;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	int C, Q;
	read(C), read(Q);
	while (Q -- )
	{
		work1.solve();
	}

	return 0;
}
