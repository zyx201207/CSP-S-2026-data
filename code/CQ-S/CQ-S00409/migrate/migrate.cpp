#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,INF=2e18;
int c,t,n,d,x[N],dis[N],vis[N],ans;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while (t--) {
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>x[i];
		for (int i=1;i<=n;i++) {
			for (int j=i;j<=n;j++) vis[j]=0;
			for (int j=i;j<=n;j++) dis[j]=INF; 
			priority_queue<pair<int,int> > q;
			q.push({0,i});
			dis[i]=0;
			while (!q.empty()) {
				int u=q.top().second,cnt=-q.top().first;
				q.pop();
				if (dis[u]!=cnt) continue;
				vis[u]++;
				for (int v=u+1;v<=n;v++) {
					if (x[v]-x[u]<=d && dis[v]>=cnt+1) {
						dis[v]=cnt+1;
						q.push({-(cnt+1),v});
					}
				}
			}
			for (int j=i;j<=n;j++) ans+=(vis[j]==2);
		} 
		cout<<ans<<"\n";
		ans=0;
	} 
	return 0;
}

