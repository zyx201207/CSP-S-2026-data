#include<bits/stdc++.h>
using namespace std;
const int N = 405;
int c,n,m,d,q,ww[N],a[N],t[N],w[N],p[N],ans;
int h[N],e[N],nxt[N],idx;
void add(int u,int v,int c){
	p[idx] = c,e[idx] = v,nxt[idx] = h[u],h[u] = idx ++;
}
void dist(int a,int b,int res){
	if(a == b) ans = min(ans,res);
	for(int i = h[a]; ~i; i = nxt[i]){
		int v = e[i];
		dist(v,b,res + p[i]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(w,0x3f,sizeof w);
	memset(h,-1,sizeof h);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> ww[i];
	for(int i = 1,k; i <= n; i++){
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[j] >> t[j];
			w[a[j]] = min(w[a[j]],t[j]);
			if(j != 1)add(a[j - 1],a[j],t[j]);
		}
	}
	while(q--){
		ans = 1e9 + 10;
		int u,v;
		cin >> u >> v;
		dist(u,v,0);
		cout << ans + ww[u] + ww[v] << '\n';
	}
	return 0;
}