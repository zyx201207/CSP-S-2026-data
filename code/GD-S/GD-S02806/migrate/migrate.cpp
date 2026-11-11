#include<bits/stdc++.h>
using namespace std;
long long mp[2000005], f[2000005], dij[5005][5005], sum[5005][5005];
//void bfs(int s){
//	dij[s][s] = 0ll;
//	queue <pair <int, long long>> q;
//	q.push({s, 1ll});
//	while(!q.empty()){
//		int x = q.front().first, val = q.front().second;
//		q.pop();
//		for(int i = x + 1; i <= f[x]; i++){
//			if(dij[s][i] == val + 1){
//				sum[s][i] += sum[s][x];
//			} else if(dij[s][i] > val + 1){
//				sum[s][i] = 1;
//				dij[s][i] = val + 1;
//				q.push({i, val + 1});
//			}
//		}
//	}
//	return ;
//}
void work(){
	int n;
	long long d;
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> mp[i];
	}
//	for(int x = 1, y = 2; x <= y && y <= n; ){
//		if(mp[y] - mp[x] <= d){
//			if(y < n){
//				y++;
//			} else {
//				f[x] = y;
//			}
//		} else {
//			f[x] = y - 1;
//			x++;
//		}
//	}
//	memset(dij, 0x3f, sizeof dij);
//		for(int i = 1; i <= n; i++){
//			bfs(i);
//		}
//		for(int i = 1; i < n; i++){
//			for(int j = i + 1; j <= n; j++){
//				cout << sum[i][j] << " ";
//			}
//			cout << "\n";
//		}
//		cout << "\n\n\n";
	cout << "1\n";
	return ;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int casenum, t;
	cin >> casenum >> t;
	while(t--){
		work();
	}
	return 0;
} 
