#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;
ll x[N],d;
ll dis[N],f[N],vis[N],n;
ll bfs(int r) {
	ll num=0;
	queue<int>q;
	q.push(r);
	for(int i=1; i<=n; i++)dis[i]=0,f[i]=0,vis[i]=0;
	f[r]=1;
	vis[r]=1;
	while(q.size()) {
		int u=q.front();
		q.pop();
		for(int i=u+1; i<=n; i++) {
			if(x[i]-x[u]>d)break;
			if(!vis[i]) {
				vis[i]=1;
				dis[i]=dis[u]+1;
				f[i]=f[u];
				q.push(i);
			} else {
				if(dis[u]+1==dis[i])f[i]=min(5ll,f[i]+f[u]);
			}
		}
	}
	for(int i=r; i<=n; i++)
		if(f[i]==2)++num;
	return num;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++)scanf("%lld",&x[i]);
		ll ans=0;
		for(int i=1; i<=n; i++)ans+=bfs(i);
		printf("%lld\n",ans);
	}
	return 0;
}
