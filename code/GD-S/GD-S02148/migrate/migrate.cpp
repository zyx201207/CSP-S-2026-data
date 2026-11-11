#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2000005;
int n, d, x[N], nxt[N], f[N], g[N], p[N], dp[N], dis[N];
void solve(){
	scanf("%lld%lld",&n,&d);
	for(int i = 1; i <= n; i ++) scanf("%lld",&x[i]), f[i] = 0, p[i] = 0;
	int z = n;
	for(int i = n; i >= 1; i --){
		while(x[z] - x[i] > d){
			z--;
		}
		nxt[i] = z;
	} 
	int ans = 0;
	if(n <= 5000){
		for(int i = n; i >= 1; i --){
			for(int j = i; j <= n; j ++){
				dis[j] = n+1;
				dp[j] = 0;
			}
			dis[i] = 0, dp[i] = 1;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int x = q.front();q.pop();
				if(dp[x]>2)continue;
				for(int v = x+1; v <= nxt[x]; v ++){
					if(dis[v] > dis[x] + 1){
						dis[v] = dis[x] + 1;
						dp[v] = dp[x];
						if(dp[x]<=2)q.push(v);
					}
					else if(dis[v] == dis[x] + 1){
						dp[v] += dp[x];
					}
				}
			}
			for(int j = i + 1; j <= n; j ++){
				if(dp[j] == 2){
					ans ++;
				}
			}
		}
		printf("%lld\n",ans);
		return;
	}
	g[n] = n;
	for(int i = n - 1; i >= 1; i --){
		if(nxt[i] == i + 1){
			f[i] = f[i+1];
			g[i] = g[i+1];
		}
		else if(nxt[i] == i) f[i] = 0, g[i] = i;
		else{
			g[i] = i;
			int h = nxt[i] - 1;
			int hh = nxt[h];
			int hhh = nxt[i];
			if(nxt[i] - i >= 3){
				hhh = max(hhh, nxt[nxt[i]-2]);
			}
			if(hh==hhh)f[i] = 0;
			else f[i] = hh - hhh + (hh==nxt[hhh] && (nxt[hh-1]==hh))*(g[hh]-hh);
		}
		ans += f[i];
	}
	printf("%lld\n",ans);
	
}
int c, T;
/*
0 1
8 3
0 1 2 4 8 10 11 13

0 1
10 3
0 3 6 7 8 9 10 11 14 17

0 1
5 3
0 2 3 4 6

0 1
7 3
0 3 6 6 8 9 10
*/
signed main (){
//	freopen("migrate6.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		solve();
	}
}
