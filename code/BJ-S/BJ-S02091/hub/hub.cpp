#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
vector<int>g[N];
int n, k, out[N], mx[N], xx, cdel;
int a[N], ca, tr[N], tl[N], deg[N];
int qq1[N], cq1, qq2[N], cq2, ss;

void slv()
{
	int i, j;
	// printf("slv %d\n", xx);
	// for(i=1;i<=ca;i++) printf("%d%c", a[i], " \n"[i==ca]);
	tl[1] = 2;
	for(i=j=2;i<=ca;i++)
	{
		while(j<i) tl[j] = j + 1, j++;
		// if(i==2) printf("j is %ddd | %d %d\n", j, mx[j], xx-(j-i));
		while(j<=ca&&a[j]<xx-(j-i)) tl[j++] = i;
	}
	while(j<=ca) tl[j] = j + 1, j++;
	for(i=j=ca-1;i>=1;i--)
	{
		while(j>i) tr[j] = j - 1, j--;
		while(j>=1&&a[j]<xx-(i-j)) tr[j--] = i;
	}
	while(j>=1) tr[j] = j - 1, j--;
	tr[ca] = ca - 1;
	// printf("tl%ddd %d\n", tl[2], tr[3]);
	while(j>=1) tr[j] = j - 1, j--;
	for(i=1;i<ca;i++) cdel = max(cdel,tr[i+1]-tl[i]+1);
}

int fa[N];
queue<int>q;
void bfs(int x)
{
	while(!q.empty()) q.pop();
	q.push(x);
	while(!q.empty())
	{
		int x = q.front();q.pop();
		// printf("dfs %d %d\n", x, f);
		for(auto j:g[x]) if(j!=fa[x]&&!out[j])
		{
			int k = j, l = x;
			a[ca=1] = mx[x];
			while(deg[k]==2)
			{
				a[++ca] = mx[k];
				int nk = 0;
				for(auto d:g[k]) if(d!=l&&!out[d]) nk = d;
				l = k, k = nk;
			}
			a[++ca] = mx[k];
			slv();
			if(n-ss-cdel<=::k) return;
			fa[k] = l;
			q.push(k);
		}
	}
}

int get(int x)
{
	int i, j, s = 0;
	cq1 = cq2 = 0;
	for(i=1;i<=n;i++)
	{
		deg[i] = (int)g[i].size(), out[i] = mx[i] = fa[i] = 0;
		if(deg[i]==1) qq1[++cq1] = i;
	}
	for(i=1;i<=x;i++)
	{
		while(cq1)
		{
			// printf("aa%d\n", cq1);
			int d = qq1[cq1--];s++, out[d] = 1;
			for(auto j:g[d]) if(!out[j])
			{
				deg[j]--, mx[j] = i;
				if(deg[j]==1) qq2[++cq2] = j;
			}
		}
		for(j=1;j<=cq2;j++) qq1[j] = qq2[j];
		cq1 = cq2, cq2 = 0;
	}
	// printf("dd %d %d %d\n", s, out[1], out[5]);
	if(s==n) return 1;
	xx = x;
	for(i=1;i<=n;i++) if(deg[i]!=2&&!out[i])
	{
		cdel = 0, ss = s, bfs(i);
		break;
	}
	return n - s - cdel;
}

int T;
int Main()
{
	int i, a, b;
	scanf("%d%d", &n, &k);
	for(i=1;i<n;i++) scanf("%d%d", &a, &b), g[a].emplace_back(b), g[b].emplace_back(a);
	// if(T!=48)
	// {
	// 	for(i=1;i<=n;i++) g[i].clear();
	// 	return 0;
	// }
	// printf("%dd\n", get(1));
	int l = 0, r = n, mid;
	while(l<r)
	{
		// printf("lr %d %d\n", l, r);
		mid = (l + r) >> 1;
		if(get(mid)<=k) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	k = xx = cdel = ss = 0;
	for(i=1;i<=n;i++) g[i].clear(), out[i] = mx[i] = ::a[i] = tr[i] = tl[i] = deg[i] = qq1[i] = qq2[i] = fa[i] = 0;
	n = k = cq1 = cq2 = ss = 0;
	return 0;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	for(T=1;T<=t;T++) Main();
	return 0;
}