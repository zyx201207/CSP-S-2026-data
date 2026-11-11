#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int X[N],n,cid,T,d,cnt[N],dis[N],vis[N],nxt[N];
void djs(int S) {
	for(int i=0;i<S;i++) dis[i]=1e18,cnt[i]=vis[i]=0;
	dis[S]=0; cnt[S]=1;
	queue<int> q;
	q.push(S);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		if(vis[u]) continue;
		if(cnt[u]>=3) continue;
		vis[u]=true;
		l=lower_bound(X+1,X+1+u,X[u]-d)-X;
		for(int v=u-1;v>=l;v--) {
			if(dis[u]+1<dis[v]) {
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}
			else if(dis[u]+1==dis[v]) cnt[v]+=cnt[u];
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cid>>T;
	while(T--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>X[i];
		int ans=0;
		for(int i=1;i<=n;i++) {
			djs(i);
			int res=0;
			for(int j=1;j<=i;j++) 
				if(cnt[j]==2) res++;
			ans+=res;
		}
		cout<<ans<<'\n';
		for(int i=0;i<=n;i++) dis[i]=cnt[i]=0;
	}
}
/*
0 1
5 2
1 2 3 4 5

*/
