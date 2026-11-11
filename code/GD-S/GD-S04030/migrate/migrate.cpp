#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
const int N = 2e6+5;
int a[N] = {};
int cnt_ds[N] = {};
struct node{
	int num,step;
};
int mx = 1e9;
void bfs(int start,int end) {
	queue<node>q;
	q.push({start,0});
	
	while(!q.empty()) {
		node now = q.front();
		q.pop();
		if(now.num == end) {
			cnt_ds[now.step] ++;
			mx = min(mx,now.step);
			continue;
		}
		if(now.step + 1 > mx) continue;
		for(int i = 1; i <= n;i ++ ) {
			if(abs(a[i]-now.num) > d) {
				continue;
			}
			q.push({a[i],now.step+1});
		}
	}
}
void solve() {
	cin >> n >> d;
	
	for(int i = 1; i <= n;i ++) {
		cin >> a[i];
	}
	int ans = 0;
	bfs(1,4);
	for(int i = 1; i <= n;i ++ ) {
		for(int j = i+1; j <= n;j ++ ) {
			if(a[i] == a[j]) {
				continue;
			}
//			cout << a[i] <<  " t " << a[j] << '\n';
			memset(cnt_ds,0,sizeof(cnt_ds));
			bfs(a[i],a[j]);
			
			for(int k = 1;k <= (n+5);k ++ ) {
				if(cnt_ds[k] == 0) continue;
				if(cnt_ds[k] == 2) {
					ans ++;
				}

			}
		} 
		
	}
	cout << ans << '\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int type;
	cin >> type;
	int t;
	cin >> t;
	
	while(t--) {
		solve();
	}
	return 0;
}

