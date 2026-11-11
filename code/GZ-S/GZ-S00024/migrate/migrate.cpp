#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define upp(a,x,y) for(int a=x;a<=y;a++)
#define dww(a,x,y) for(int a=x;a>=y;a--)
#define pb push_back
#define x first
#define y second
#define endl '\n'
using namespace std;
const int N=5010;
/*
f[i] 表示将 i 作为中途点，且前面无 2 的方案数
g[i] 表示将 i 作为到达点，且后无 2 的方案数 
*/
int dist[N],st[N],p[N];
int a[N],ans;
int n,d,cid;
vector<int> e[N];
void dijkstra(int u) {
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	memset(p,0,sizeof p);
	priority_queue<PII,vector<PII>,greater<PII>> qq;
	qq.push({0,u});
	dist[u]=0;
	p[u]=1;
	while(qq.size()) {
		auto iter=qq.top();
		qq.pop();
		int ver=iter.y;
		if(st[ver]) continue;
		st[ver]=1;
		for(auto j:e[ver]) {
			if(dist[j]>dist[ver]+1) {
				dist[j]=dist[ver]+1;
				p[j]=p[ver];
				qq.push({dist[j],j});
			}
			else if(dist[j]==dist[ver]+1) {
				p[j]+=p[ver];
			}
			if(p[j]>2) p[j]=3;
		}
	}
	upp(i,1,n) if(p[i]==2) {
		ans++;
	}
}
void solve() {
	ans=0;
	cin>>n>>d;
	upp(i,1,n) cin>>a[i],e[i].clear();
	upp(i,1,n) {
		upp(j,i+1,n) {
			if(a[j]-a[i]<=d)
			e[i].pb(j);
		}
	}
	upp(i,1,n) {
		dijkstra(i);
	}
	cout<<ans<<endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int tt;cin>>cid>>tt;
	while(tt--) solve();
	return 0;
}
/*
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/

