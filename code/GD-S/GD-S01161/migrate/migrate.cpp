#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5+7;
const long long M = 1e18;
long long a[N], b[N], q[N]; 
long long n,m;
long long check(long long x){
	memset(q,0,sizeof(q));
	long long op = 0;
	for(long long i = 1; i <= n; i++) if(x >= a[i]) q[++op] = x - a[i];
	long long qq = 0;
	sort(q+1,q+op+1);
	for(long long i = 1; i <= op; i++){
		qq += q[i];
		if(qq > m) return i - 1;
	}
	return op;
}
int main(){
  	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T; cin >> T;
	while(T--){
		cin >> n >> m;
		long long l = M, r = -1;
		for(long long i = 1; i <= n; i++){
			cin >> a[i];
			l = min(l , a[i]);
			r = max(r, a[i]); 
		}
		if((r-l) <= 500){
			long long ans = 0;
			sort(a+1,a+n+1);
			for(long long i = l; i <= r; i++){
				ans = max(ans,check(i));
			}
			cout << ans;
			return 0;
		}else{
			bool tt = 1;
			for(long long i = 1; i <= n; i++){
				if(a[i] != i) tt = 0;
			}
			if(tt){
				long long len = 0;
				for(long long i = 1; i <= (n/2); i++){
					len = len + i;
					if(len + len > m){
						cout << 2*(i-1) + 1;
						return 0;
					} 
				}
			}
			long long len = 0;
			long long p = a[2] - a[1];
			for(int i = 1; i <= (n/2); i+=p){
				len += i;
				if(len + len > m){
					cout << 2*(i-1) + 1;
					return 0;
				} 
			}
		} 
	}	
	return 0;
}
