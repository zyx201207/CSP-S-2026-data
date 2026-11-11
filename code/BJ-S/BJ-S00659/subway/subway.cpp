#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstdio>
using namespace std ;
long long d[510][510] , c , n , m , dd , q ;
signed main(){
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&dd,&q) ;
	vector<long long> w(m+1) ;
	for(long long i = 1 ; i <= m ; i++){
		scanf("%lld",&w[i]) ;
	}
	for(long long i = 1 ; i <= n ; i++){
		for(long long j = 1 ; j <= n ; j++){
			if(i != j)d[i][j] = 1e18 ;
		}
	}
	vector<long long> a[510] ;
	vector<long long> t[510] ;
	unordered_map<long long,vector<pair<long long,long long>>> mp ;
	for(long long i = 1 ; i <= n ; i++){
		long long k ;
		scanf("%lld",&k) ;
		for(long long j = 0 ; j < k ; j++){
			long long x , y ;
			scanf("%lld%lld",&x,&y) ;
			a[i].emplace_back(x) ;
			t[i].emplace_back(y) ;
			if(mp.find(x) != mp.end()){
				for(auto [e,in] : mp[x]){
					d[e][i] = d[i][e] = min(min(d[i][e],d[e][i]),
						in+y) ;
				}
			}
			mp[x].emplace_back(i,y) ;
		}
	}
	for(long long k = 1 ; k <= n ; k++){
		for(long long i = 1 ; i <= n ; i++){
			for(long long j = 1 ; j <= n ; j++){
				if(d[i][k]+d[k][j]<d[i][j]) d[i][j] = d[i][k]+d[k][j] ;
			}
		}
	}
	while(q--){
		long long x , y ;
		scanf("%lld%lld",&x,&y) ;
		long long minn = 1e18 ;
		for(auto [u,in1] : mp[x]){
			for(auto [v,in2] : mp[y]){
				minn = min(minn,d[u][v]+w[x]+w[y]+in1+in2) ;
			}
		}
		printf("%lld\n",minn) ;
	}
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}