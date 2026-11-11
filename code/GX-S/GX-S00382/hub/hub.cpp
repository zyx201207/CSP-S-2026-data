#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define qwq Ff472130
#define ll long long
#define f(i,l,r) for (int i=l;i<=r;i++)
#define F(i,r,l) for (int i=r;i>=l;i--)
constexpr int N=2e6+10;
constexpr int inf=1e9+10;

inline void read(int &x) {
	x=0;
	char ch=getchar();
	while (ch<48) ch=getchar();
	while (ch>=48) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}

int n,k,ans;
int vis[N];
vector<int> e[N];

int f[N],dis[N];
inline int find(int x) {
	if (f[x]==x) return x;
	return f[x]=find(f[x]);
}

inline void calc() {
	static int did[N];
	f(i,1,n) f[i]=i,dis[i]=inf,did[i]=0;
	f(i,1,n) if (vis[i]) {
		for (int v:e[i]) if (vis[v]) {
			int u=find(i);v=find(v);
			if (u!=v) f[u]=v;
		}
	}
	f(i,1,n) if (vis[i]) did[find(i)]=1;
	int sum=0;
	f(i,1,n) sum+=did[i];
	if (sum>2) return;
	queue<int> q;
	f(i,1,n) if (vis[i]) dis[i]=0,q.push(i);
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (int v:e[now]) {
			if (dis[v]<=dis[now]+1) continue;
			dis[v]=dis[now]+1;
			q.push(v);
		}
	}
	int mx=0;
	f(i,1,n) mx=max(mx,dis[i]);
	ans=min(ans,mx);
}

inline void dfs(int now,int s) {
	if (now==n+1) {
		if (s==k) calc();
		return;
	}
	vis[now]=0;
	dfs(now+1,s);
	if (s!=k) {
		vis[now]=1;
		dfs(now+1,s+1);
	}
}

inline void solve() {
	read(n);read(k);ans=n;
	f(i,2,n) {
		int u,v;read(u);read(v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	printf("%d\n",ans);
	f(i,1,n) e[i].clear();
}

int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	int C,T;read(C);read(T);
	while (T--) solve();
	return 0;
}

