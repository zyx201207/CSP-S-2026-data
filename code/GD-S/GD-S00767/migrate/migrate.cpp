#include<bits/stdc++.h>
using namespace std;
void solve_small(){
	int n,k;
	cin >> n >> k;
	vector<vector<int>> dist(n+1,vector<int>(n+1));
	
}
void sloveA(){
	long long n,k;
	cin >> n >> k;
	vector<long long> v(n+1);
	for(long long i=1;i<=n;i++) cin >> v[i];
	long long d = v[2] - v[1];
	long long maxn = (k/d)*d;
	long long maxx = maxn - d;
	long long nt = (v[n] - v[1]);
	long long mm = (maxn + maxx);
	long long ans = ( nt - mm ) / d + 1;
	if(d >= k or (nt - mm) < 0){
		cout << 0 << '\n';
		return ;
	}
	cout << ans << '\n';
	
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	long long c,T;
	cin >> c >> T;
	if(c==0 or 11 <= c and c <= 12) while(T--) sloveA();
	
	
	return 0;
}
