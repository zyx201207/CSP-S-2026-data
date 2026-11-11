#include<bits/stdc++.h>
using namespace std;
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define ll long long
const int N = 5e3+5,M = N*(N-1)/2,inf = 1e9;
int n,ans;
ll d,a[N];
int head[N],nxt[M<<1],to[M<<1],cnt;
void add(int u,int v){nxt[++cnt] = head[u],to[cnt] = v,head[u] = cnt;}
int dis[N],sum[N];
queue<int> q;
void bfs(int s){
	for(int i = 1;i<=n;i++) dis[i] = inf,sum[i] = 0;
	dis[s] = 0;
	sum[s] = 1;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int e = head[u],v;e;e = nxt[e]){
			v = to[e];
			if(dis[v]>dis[u]+1){
				dis[v] = dis[u]+1;
				sum[v] = 0;
				q.push(v);
			}
			if(dis[v]==dis[u]+1) sum[v]+=sum[u];
		}
	}
}
void init(){
	cnt = 0;
	for(int i = 1;i<=n;i++) head[i] = 0;
}
void solve(){
	cin >> n >> d;
	init();
	for(int i = 1;i<=n;i++) cin >> a[i];
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(a[j]-a[i]<=d) add(i,j),add(j,i);
			else break;
		}
	}
	ans = 0;
	for(int i = 1;i<=n;i++){
		bfs(i);
		for(int j = i+1;j<=n;j++){
			if(sum[j]==2) ans++;
		}
	}
	cout << ans << '\n';
}
signed main(){
	fre("migrate");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin >> c >> T;
	while(T--) solve();
	return 0;
}
