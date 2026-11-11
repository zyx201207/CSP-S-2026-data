#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mpi make_pair
#define fi first
#define se second
#define lb(x) (x&-x)
using namespace std;
const int maxn=2e6+10;
const int maxm=1e6+10;
const int INF=1e18;
const int mod=998244353;
int c,T,n,d,a[maxn],pre[maxn],nxt[maxn],k[maxn],f1[maxn],f2[maxn],t;
vector <int> mx[maxn];
struct node
{
	int fa[maxn];
	void init(){for (int i=1;i<=n;i++) fa[i]=i;}
	int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
	void merge(int x,int y){fa[find(x)]=find(y);}
}d1,d2;
struct tree
{
	vector <int> son[maxn];
	int f[maxn];
	void init(){for (int i=1;i<=n;i++) son[i].clear(),f[i]=0;}
	void add(int u,int v){son[u].push_back(v);}
	void dfs(int x)
	{
		if (f[x]) return;
		f[x]=1,t--;
//		cout << x << "\n";
		for (auto y:son[x]) dfs(y);
	}
}t1,t2;
void solve()
{
	cin >> n >> d;
	for (int i=1;i<=n;i++) cin >> a[i];
	t1.init(),t2.init();
	for (int i=1,j=1;i<=n;i++)
	{
		while (a[j]+d<a[i]) j++;
		pre[i]=j;
		if (pre[i]<i) t1.add(pre[i],i);
	}
	for (int i=n,j=n;i>=1;i--)
	{
		while (a[j]-d>a[i]) j--;
		nxt[i]=j;
		if (nxt[i]>i) t2.add(nxt[i],i);
	}
	for (int i=1;i<=n;i++) f1[i]=(pre[i]<i&&(pre[i]==i-1||pre[pre[i]]!=pre[pre[i]+1]))*f1[pre[i]]+1;
	for (int i=n;i>=1;i--) f2[i]=(nxt[i]>i&&(nxt[i]==i+1||nxt[nxt[i]]!=nxt[nxt[i]-1]))*f2[nxt[i]]+1;
	d1.init(),d2.init();
	for (int i=1,j=1;i<=n;i++)
	{
		while (j<n&&d1.find(pre[j+1])==d1.find(pre[i])) j++;
		while (i<j) d1.merge(i,i+1),i++;
	}
	for (int i=n,j=n;i>=1;i--)
	{
		while (j>1&&d2.find(nxt[j-1])==d2.find(nxt[i])) j--;
		while (i>j) d2.merge(i,i-1),i--;
	}
	for (int i=1;i<=n;i++) mx[i].clear();
	t=0;
	for (int i=1;i<=n;i++)
	{
		t++;
		if (pre[i]<i) for (auto u:mx[pre[i]]) t2.dfs(u);
		if (nxt[i]>i+1) mx[nxt[i]-1].push_back(i);
		f1[i]=t;
	}
	for (int i=1;i<=n;i++) mx[i].clear();
	t=0;
//	cout << "-----------\n";
	for (int i=n;i>=1;i--)
	{
		t++;
//		cout << i << "---------------\n";
		if (nxt[i]>i) for (auto u:mx[nxt[i]]) t1.dfs(u);
		if (pre[i]<i-1) mx[pre[i]+1].push_back(i);
		f2[i]=t;
	}
//	for (int i=1;i<=n;i++) cout << pre[i] << " ";
//	cout << "\n";
//	for (int i=1;i<=n;i++) cout << nxt[i] << " ";
//	cout << "\n";
//	for (int i=1;i<=n;i++) cout << f1[i] << " ";
//	cout << "\n";
//	for (int i=1;i<=n;i++) cout << f2[i] << " ";
//	cout << "\n";
//	for (int i=1;i<=n;i++) cout << d1.find(i) << " ";
//	cout << "\n";
//	for (int i=1;i<=n;i++) cout << d2.find(i) << " ";
//	cout << "\n";
	for (int i=1;i<=n;i++) k[i]=0;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (pre[i]<i) ans+=k[pre[i]]*(pre[i+1]<=pre[i]+1||(i<n&&d2.find(i)==d2.find(i-1))?1:f2[i]);
		if (nxt[i]>i+1) k[nxt[i]-1]+=(nxt[i-1]>=nxt[i]-1||(i>1&&d1.find(i)==d1.find(i+1))?1:f1[i]);
//		cout << ans << " ";
	}
	cout << ans << "\n";
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("my.out","w",stdout);
	cin >> c >> T;
	while (T--) solve();
	return 0;
}
/*
0 1
10 20
12 16 24 29 34 45 63 65 70 73 

1 9
1 10
2 6
2 7
2 8
3 6
3 7
3 8
4 9
4 10
5 9
5 10
6 9
6 10
*/ 
