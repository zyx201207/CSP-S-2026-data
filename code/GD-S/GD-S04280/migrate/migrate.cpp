#include<bits/stdc++.h>
using namespace std;
long long c, TTTTT;
const int MAXN = 2e5 + 7;
long long n, d;
long long a[MAXN];
long long ma[MAXN], mas[MAXN];
long long dist[5001][5001];
void clean(){
	memset(a, 0, sizeof(a));
	memset(mas, 1, sizeof(mas));
	memset(dist, -1, sizeof(dist));
}
void solve(){
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			for(int k = i + 1; k < j; k++){
				if(k == j) continue;
				if(dist[i][k] == -1) break;
				if(dist[j][k] == -1) continue;
				if(dist[i][j] == -1){
					dist[i][j] = dist[i][k] + dist[k][j]; 
					mas[j] = 1;
				}
				else if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[j][k];
					mas[j] = 1;
				}
				else if(dist[i][k] + dist[k][j] == dist[i][j]){
					mas[j]++;
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> TTTTT;
	while(TTTTT--){
		clean();
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(a[j] - a[i] > d) break;
				dist[i][j] = 1;
				dist[j][i] = 1;
			}
		}
		solve();
		int sum = 0;
		for(int i = 1; i <= n; i++){
			if(mas[i] == 2) sum++;
		}
		cout << sum << endl;
	}
	return 0;
}
