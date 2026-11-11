#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9+7;
int a[4010][4010],n,k,ans;
int s[4010],f[4010];
int vis[4010],d[4010];
int u[4010],v[4010];
int find(int now){
	if(f[now] == now){
		return now;
	}
	return f[now] = find(f[now]);
}
bool check(){
	for(int i = 1;i <= n;i++){
		f[i] = i;
	}
	for(int i = 1;i < n;i++){
		if(s[u[i]] && s[v[i]]){
			int x = find(u[i]),y = find(v[i]);
			if(x != y){
				f[v[i]] = x;
			}
		}
	}
	memset(vis,0,sizeof(vis));
	int sum = 0;
	for(int i = 1;i <= n;i++){
		if(!s[i]){
			continue; 
		}
		int l = find(i);
		if(!vis[l]){
			vis[l] = 1;
			sum++;
		}
		if(sum > 2){
			return 0;
		}
	}
	return 1;
}
void floyd(){
	memset(d,INF,sizeof(d));
	for(int i = 1;i <= n;i++){
		if(s[i]){
			d[i] = 0;
			continue;
		}
		for(int j = 1;j <= n;j++){
			if(!s[j]){
				continue;
			}
		    d[i] = min(d[i],a[i][j]);
		}
	}
	int maxn = 0;
	for(int i = 1;i <= n;i++){
		maxn = max(maxn,d[i]);
	}
	ans = min(ans,maxn);
}
void dfs(int now,int sum){
	if(now > n){
		if(sum == 0){
		    if(check()){
		    	floyd();
	    	}
    	}
		return;
	}
	if(sum > 0){
		s[now] = 1;
		dfs(now+1,sum-1);
	}
	s[now] = 0;
	dfs(now+1,sum);
}
void solve(){
	ans = INF;
	cin>> n >> k;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			a[i][j] = INF;
		}
	}
	for(int i = 1;i < n;i++){
		cin>> u[i] >> v[i];
		a[u[i]][v[i]] = 1;
		a[v[i]][u[i]] = 1;
		a[i][i] = 0;
	}
	a[n][n] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j){
				continue;
			}
			for(int K = 1;K <= n;K++){
				if(i == K || j == K){
					continue;
				}
				a[i][j] = min(a[i][j],a[i][K]+a[K][j]);
			}
		}
	}
	memset(s,0,sizeof(s));
	dfs(1,k);
	cout<< ans << "\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
