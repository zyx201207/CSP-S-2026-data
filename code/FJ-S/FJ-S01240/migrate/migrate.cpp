#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t, n, ans, minn, cnt, ed;
ll x[2123456];
bool vis[2123456];
unsigned long long d;
void dfs(int now, int k){
	if(now==ed){
		if(k==minn) cnt++;
		else if(k<minn){
			minn=k;
			cnt=1;
		}
		return;
	}
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		if(abs(x[i]-x[now])>d) continue;
		vis[i]=true;
		dfs(x[i], k+1);
		vis[i]=false;
	}
	return;
}
bool check(int xi, int xj){
	minn=INT_MAX;
	cnt=0;
	ed=xj;
	dfs(xi, 0);
	if(cnt==2) return true;
	return false;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%lld", &n, &d);
		ans=0;
		for(int i=1; i<=n; i++) vis[i]=false;
		for(int i=1; i<=n; i++) scanf("%lld", &x[i]);
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				if(check(i, j)) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
