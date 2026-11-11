#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0;
int c,t;
int n,d;
int x[2000001];
vector<int>g[5001];
int ind[5001];
int cnt[5001];
int dis[5001];
queue<int>q;
void baoli() {
	ans=0;
	for(int i=1; i<=n; i++) {
		for(int j=n; j>=i; j--) {
			for(int k=n; k>j; k--) {
				if(abs(x[j]-x[k])<=d) {
					g[j].push_back(k);
					ind[k]++;
				}
			}
		}
		for(int j=1; j<=n; j++)cnt[j]=0,dis[j]=LLONG_MAX;
		cnt[i]=1;
		dis[i]=0;
		q.push(i);
		while(!q.empty()) {
			int u=q.front();
			q.pop();
			for(int j=0; j<g[u].size(); j++) {
				int v=g[u][j];
				ind[v]--;
				if(dis[v]>dis[u]+1) {
					cnt[v]=cnt[u];
					dis[v]=dis[u]+1;
				} else if(dis[v]==dis[u]+1) {
					cnt[v]+=cnt[u];
				}
				if(ind[v]==0) {
					q.push(v);
				}
			}
		}
		for(int j=1; j<=n; j++) {
			if(cnt[j]==2) {
				ans++;
			}
		}
		for(int j=1; j<=n; j++)g[j].clear(),ind[j]=0;
	}
	cout<<ans<<endl;
}
void solve() {
	scanf("%lld%lld",&n,&d);
	for(int i=1; i<=n; i++)scanf("%lld",&x[i]);
	if(n<=600)baoli();
	else cout<<0<<endl;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) {
		solve();
	}
}
