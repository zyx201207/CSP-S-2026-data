#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, x[2000000], mn;
long long ans[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> c;
	if(c != 0) return 0;
	cin >> t;
	while(t--){
		cin >> n >> d;
		mn = INT_MAX;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
			if(i > 1) mn = min(mn,x[i]-x[i-1]);
		}
		if(mn > d || n == 1 || n == 2 || n == 3){cout << 0;continue;}
		int g = x[2]-x[1], mng, mxg;
		for(int i = 1; i < n; i++){
			if(g * i <= d) mng = i;
		}
		for(int i = n-1; i >= 1; i--){
			if(g * i >= d) mxg = i;
		}
		long long a = 0;
		for(int i = (g*mng < d ? mng+1 : mng); i <= (g*mxg > d ? mxg-1 : mxg); i++){
			a += n-i-1;
		}
		cout << a << '\n';
	}
	return 0;
}
