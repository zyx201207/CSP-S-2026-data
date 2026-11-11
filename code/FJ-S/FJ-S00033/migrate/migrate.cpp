#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 2000005;
int c, T;
int n, x[MAXN], d;

int floyd[300][300];
int cnt[300][300];

void Main(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}
	if(d >= x[n] - x[1]) {
		cout << 0 << endl;
		return;
	}
	if(c <= 6){ // 建图大蛇 
		memset(floyd, 0x3f, sizeof(floyd));
		for(int i = 1; i < n; i++)
			for(int j = i+1; j <= n; j++)
				if(x[j]-x[i] <= d){
					floyd[i][j] = floyd[j][i] = 1;
				}
		for(int i = 1; i <= n; i++)
			floyd[i][i] = 0;
		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++){
					if(k == i || k == j || i == j) continue;
					int last = floyd[i][j];
					floyd[i][j] = floyd[j][i] = min(floyd[i][j], floyd[i][k]+floyd[k][j]);
					int neww = floyd[i][j];
					if(last > neww) cnt[i][j] = 1;
					if(last == neww) {
						cnt[i][j]++;
						
					}
				}
					
		int ans = 0;
		for(int i = 1; i < n; i++){
			for(int j = i+1; j <= n; j++){
				if(x[j]-x[i] <= d) continue;
				if(cnt[i][j] == 2) ans++;
			}
		}
		cout << ans << endl;
		return;
	}
	if(c == 11 || c == 12){
		if(x[2]-x[1] >= d){
			cout << 0 << endl;
			return;
		}
		int mk = d / (x[2]-x[1]);
		if(mk == 2){
			cout << n-3 << endl;
			return;
		}
		else{
			cout << max(0ll, n-2*mk+1) << endl;
			return;
		}
	}
	if(c == 13 || c == 14){
		// 首先抓出这个点
		bool flag=0;
		int X = 1;
		for(int i = 1; i <= n; i++){
			if(x[i]-x[1] <= d && x[n]-x[i] <= d){
				if(flag){
					cout << 0 << endl;
					return;
				}
				X = i;
				flag = 1;
			}
		}
		cout << 2 << endl;
		return;
	}
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> T;
	while(T--){
		Main();
	}
	return 0;
}
