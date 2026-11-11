#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 105;
const ll INF = 1e9+5;
ll c, t; 
ll n, d;
ll a[maxn];
ll dp[maxn][maxn];//第i个岛屿到第j个岛屿的最短路径
ll x[maxn][maxn];
int cnt = 0; 
int f(int i, int j){
	if(dp[i][j] != INF) return dp[i][j];
	if(a[j] - a[i] <= d){dp[i][j] = 1; x[i][j] = 1; return 1;}
	for(int k = i + 1; k < j; k++){
		int aa = f(i, k);
		int bb = f(k, j);
		if(aa + bb == dp[i][j]){
			x[i][j]++;
		}
		if(aa + bb < dp[i][j]){
			dp[i][j] = aa + bb;
			x[i][j] = 1;
		}
	}
	return dp[i][j];
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		cnt = 0;
		for(int i = 0; i <= n + 5; i++){
			for(int j = 0; j <= n + 5; j++){
				dp[i][j] = INF;
			}
		}
		memset(x, 0, sizeof(x)); 
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				dp[i][j] = f(i, j);
			}
		} 
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				if(x[i][j] == 2) cnt++; 
				//cout << i  << " "<< j << " "<< dp[i][j]  << " " << x[i][j] << "\n";
			} 
		}
		cout << cnt << "\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*//*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5 
*/
