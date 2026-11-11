#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5010;
void file() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
int n,fw;
ll d,a[N],c[N],mn[N];
void dfs(ll u,ll step) {
	//printf("[D] step:%d old_mn:%d\n",step,(mn[u]==0x3f3f3f3f3f3f3f3f?-1:mn[u]));
	if(step==mn[u]) c[u]++;
	if(step<mn[u])  (mn[u]=step, c[u]=1);
	if(step>mn[u])  return;
	//printf("[D] %lld: c=%lld, mn=%lld\n",u,c[u],(mn[u]==0x3f3f3f3f3f3f3f3f?-1:mn[u]));
	for(int i=u+1;i<=n;i++) {
		if(a[i]-a[u]>d) break;
		dfs(i,step+1);
	}
} 
void solve() {
	cin >> n >> d;
	for(int i=1;i<=n;i++) cin >> a[i];
	ll ans = 0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) (c[j]=0, mn[j]=0x3f3f3f3f3f3f3f3f);
		dfs(1ll*i,0ll);
		for(int j=i+1;j<=n;j++) 
			if(c[j]==2) ans++;
	}
	cout << ans << '\n';
}
int main() {
	file();
	int t=1;
	cin >> fw >> t;
	while(t--) solve();
}
