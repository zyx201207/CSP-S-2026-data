#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 505, M = 5e5+5;

int c, n, m, d, q;
int w[M], k[N], cnt[M];
ll s[N][N];
vector<int> a[N], t[N], st[M], tim[M];

void read(int &x)
{
	char ch = getchar(); x = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = x*10+ch-'0', ch = getchar();
}

void write(ll x)
{
	char ch[20];
	short top = 0;
	if(!x)
	{
		putchar('0');
		putchar('\n');
		return ;
	}
	while(x)
	{
		ch[++top] = x%10+'0';
		x /= 10;
	}
	while(top) putchar(ch[top--]);
	putchar('\n');
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	read(c), read(n), read(m), read(d), read(q);
	for(int i = 1; i <= m; i++)
	{
//		scanf("%d", &w[i]);
		read(w[i]);
		st[i].push_back(0);
		tim[i].push_back(0);
	}
	for(int i = 1; i <= n; i++)
	{
//		scanf("%d", &k[i]);
		read(k[i]);
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j = 1; j <= k[i]; j++)
		{
			int A, T;
//			scanf("%d%d", &A, &T);
			read(A), read(T);
			a[i].push_back(A);
			t[i].push_back(T); 
			st[A].push_back(i);
			tim[A].push_back(T);
			cnt[A]++;
		}
		for(int j = 1; j <= n; j++) if(i != j) s[i][j] = 1e18;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k[i]; j++)
		{
			int u = a[i][j], tmp = t[i][j];
			for(int l = 1; l <= cnt[u]; l++)
			{
				int v = st[u][l];
				ll T = tim[u][l];
				s[i][v] = s[v][i] = min(s[i][v], tmp+T);
			}
		}
	for(int l = 1; l <= n; l++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				s[i][j] = min(s[i][j], s[i][l]+s[l][j]);
	while(q--)
	{
		int x, y;
		ll ans = 1e18;
//		scanf("%d%d", &x, &y);
		read(x), read(y);
		for(int i = 1; i <= cnt[x]; i++)
			for(int j = 1; j <= cnt[y]; j++)
				ans = min(ans, tim[x][i]+tim[y][j]+s[st[x][i]][st[y][j]]);
//		printf("%lld\n", ans+w[x]+w[y]);
		write(ans+w[x]+w[y]);
	}
	
	return 0;
}
