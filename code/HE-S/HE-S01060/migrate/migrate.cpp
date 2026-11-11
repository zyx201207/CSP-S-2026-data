#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M = 2001000 , I = 4e18;
int _c , T , n , d , x[M] , ans , f[M] , g[M];

int lb(int w){ return lower_bound(x , x + n , w) - x; }
int ub(int w){ return upper_bound(x , x + n , w) - x; }

signed main(){
	freopen("migrate.in" , "r" , stdin) , freopen("migrate.out" , "w" , stdout);
	// freopen("data.in" , "r" , stdin) , freopen("data.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

	cin>>_c>>T;
	while(T--){
		cin>>n>>d , ans = 0 , x[n] = I;
		for(int i = 0; i < n; ++i) cin>>x[i];
		for(int i = 0; i < n; ++i){
			int j = lb(x[i] - d) , k = min(lb(x[i + 1] - d) , i);
			if(j < i && x[i + 1] - x[j] > d) f[i] = f[j];
			else f[i] = 0;
			f[i] += k - j;
		}
		for(int i = n - 1; ~i; --i){
			int j = ub(x[i] + d) - 1 , k = i ? max(ub(x[i - 1] + d) - 1 , i) : 0;
			if(j > i && (!i || x[j] - x[i - 1] > d)) g[i] = g[j];
			else g[i] = 0;
			g[i] += j - k;
		}
		for(int p = 1; p < n - 2; ++p){
			int q = p + 1 , u , v;
			if(x[q] - x[p] >= d) continue;
			int jl = lb(x[q] - d) , kl = min(lb(x[q + 1] - d) , p);
			u = jl < p && x[q + 1] - x[jl] > d && x[p] - (jl ? x[jl - 1] : -I) > d ? f[jl] : 0;
			u += kl - jl;
			int jr = ub(x[p] + d) - 1 , kr = max(ub(x[p - 1] + d) - 1 , q);
			v = jr > q && x[jr] - x[p - 1] > d && x[jr + 1] - x[q] > d ? g[jr] : 0;
			v += jr - kr;
			ans += u * v;
		}
		cout<<ans<<'\n';
	}

	return 0;
}