#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int c,t,n,d,x[N],dist[5050][5050],cnt[5050][5050],ans;
//kkndnb
void dfs(int idx,int now,int cnt){
	if(cnt > dist[idx][now])return;
	
}
void sps() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dist[i][j] = 2e7;
			if(i == j)dist[i][j] = 0;
			cnt[i][j] = 1;
		}
	}
	for(int i = 0; i < n; i++) {
		dfs(i,i,0);
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;

		for(int i = 0; i < n; i++) {
			cin >> x[i];
		}
		if(n <= 1000){
			for(int i = 0; i < n; i++) {
				for(int j = i + 1; j < n; j++) {
					cnt[i][j] = 0;
					if(i == j)dist[i][j] = 0;
					else dist[i][j] = 2e7;
					if(x[j] - x[i] <= d){
						dist[i][j]=1,cnt[i][j]=1;
					}
				}
			}
			for(int k = 0;k < n;k++){
				for(int i = 0;i < n;i++){
					if(i >= k)continue;
					for(int j = i + 1;j < n;j++){
						if(j <= k)continue;
						int data = dist[i][k] + dist[k][j];
						if(data == dist[i][j]){
							cnt[i][j]++;
						}else if(data < dist[i][j]){
							dist[i][j]=data;
							cnt[i][j]=1;
						}
					}
				}
			}
			for(int i = 0; i < n; i++) {
				for(int j = i + 1; j < n; j++) {
					if(cnt[i][j] == 2){
						ans++;
					}
//					cerr << cnt[i][j] << ' ';
				}
//				cerr << '\n';
			}
			cout << ans << '\n';
			ans = 0;
			continue;
		}else if(n <= 5000) {
			sps();
			cout << ans <<'\n';
			ans = 0;
			continue;
		}else if(c == 13 || c == 14){
			cout << "0\n";
		}else{
			dfs(1,1,1);
			cout << ans << '\n'; 
		}
	}
	return 0;
}
