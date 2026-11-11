#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,cnt[5005],ans,a[5005],dis[5005];
vector<int>to[5005];
queue<int>q;
void bfs(int s) {
	for(int i=1;i<=n;i++)cnt[i]=0,dis[i]=0x3f3f3f3f;
	q.push(s),cnt[s]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int v:to[u]) {
			if(!cnt[v])dis[v]=dis[u]+1,cnt[v]=cnt[u],q.push(v);
			else if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
		}
	}
	for(int i=s+1;i<=n;i++)if(cnt[i]==2)ans++;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>T;
	while(T--) {
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++)to[i].clear();
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)for(int j=1;j<i;j++)if(a[i]-a[j]<=d)to[i].push_back(j),to[j].push_back(i); 
		for(int i=1;i<=n;i++)bfs(i);
		cout<<ans<<endl;
	}
	return 0;
}
