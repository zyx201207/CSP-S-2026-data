#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll c,n,m,d,q;
ll s[500005],b2[500005],dp[505][505],f[505][505];
struct d{
	vector<ll> x,y;
}b[505],a[505];
vector<int> AC[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++)
		cin >> s[i];
	for(int i = 1;i <= n;i ++){
		ll t;
		cin >> t;
		while(t --){
			ll x,y;
			cin >> x >> y;
			AC[x].push_back(i);
			if(b2[x] >= 1){
				for(size_t j = 0;j < b[x].x.size();j ++){
					a[b[x].x[j]].x.push_back(i),a[b[x].x[j]].y.push_back(y);
					a[i].x.push_back(b[x].x[j]),a[i].y.push_back(b[x].y[j]);
					f[i][j] = 1;
				}
			} 
			b2[x] ++,b[x].x.push_back(i),b[x].y.push_back(y);
		}
	}
//	for(int i = 1;i <= n;i ++){
//		for(size_t j = 0;j < a[i].x.size();j ++){
//			cout << a[i].x[j] << ' ' << a[i].y[j] << '\n';
//		}
//	} 
	for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n;j ++)
				dp[i][j] = 1e18;
	for(int q = 1;q <= d;q ++)
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				if(i == j)
					dp[i][j] = 0;
				else{
					for(ll k = 0;k < a[j].x.size();k ++){
						dp[i][j] = min(dp[i][j],dp[i][a[j].x[k]] + a[j].y[k] + a[a[j].x[k]].y[k]);
					}
				}
			}
	 	}
	while(q --){
		ll x,y,sum = 1e18,_1,_2;
		cin >> x >> y;
		for(int i = 0;i < AC[x].size();i ++)
			for(int j = 0;j < AC[y].size();j ++)
				sum = min(dp[AC[x][i]][AC[y][j]],sum);
		cout << sum + s[x] + s[y] << '\n';
	}
	return 0;
}
/*
0 5 4 20 2
2 3 4 5 
2 1 3 2 4
2 2 5 3 6
2 3 7 4 8
2 4 9 1 10
2 2 11 4 12
*/
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

