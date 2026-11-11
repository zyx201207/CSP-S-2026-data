#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
long long c, t, n, d, ans, x[N], f[N], g[N], dp[N], topp[N];
inline int id(long long x){
	return (x <= 0 ? 0 : (int)topp[x]);
}
inline void solve(){
	cin>>n>>d, ans = 0;
	for(int i = 1;i <= n;i = -~i) cin>>x[i];
	for(int i = n;i >= 1;i = ~-i){
		topp[i] = (i == n ? n : topp[i + 1]); 
		while(x[topp[i]] - x[i] > d) topp[i] --;
//		cout<<i<<' '<<topp[i]<<"!!\n";
	}
//	cout<<'\n';
	for(int i = n;i >= 1;i = ~-i){
		f[i] = g[i] = dp[i] = 0;
		if(id(i) == i) continue;
		if(id(i - 1) == id(i)){
			if(id(i - 2) == id(i)) f[i] = 0;
			else f[i] = dp[id(i)] + id(i) - max(id(i - 2), i);
		}else{
			if(id(i - 1) == id(i) - 1) f[i] = g[i] = g[id(i)];
			else f[i] = g[i] = f[id(i)];
			f[i] += max(0, id(i - 1) - max(id(i - 2), i));
			dp[i] = dp[id(i)] + id(i) - max(i, id(i - 1));
		}
		ans += f[id(i)];
//		cout<<i<<' '<<f[i]<<' '<<g[i]<<' '<<dp[i]<<' '<<ans<<"??\n";
	} 
	cout<<ans<<'\n';
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>c>>t;
	while(t --) solve();
	return 0;
} 
