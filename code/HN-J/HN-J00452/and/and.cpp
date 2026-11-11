// 疑似 dp，但时间不够跑，最坏情况 4e10 
// 用 f[i][j] 表示在第 i 个数时，选了 m 个数时最大值 
// %%% dlc666 %%% Alan Turing
// 再见 CCF，再见 mq，dlc666（这是一个好 les）  
#include<bits/stdc++.h>
using namespace std;
const int  N = 2e5 + 5;
int a[N];

int upbit(int x) {
	int k = 0;
	while((1 << k) < x) {
		k++;
	}
	return k;
}

/* begin - 9:50 */ 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n; cin >> n;
	int m; cin >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	// 暴力分支 
//	if(n <= 0) {
//		vector<vector<int>> f(n + 1);
//		for(int i = 0; i <= n; i++) {
//			f[i].resize(m + 1);
//		}
//		
//		for(int i = 1; i <= n; i++) {
//			f[i][1] = max(f[i - 1][1], a[i]);
//			for(int j = 2; j <= m; j++) {
//				f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] & a[i]);
//			}
//		}
//		
//		cout << f[n][m] << endl;
//		return 0;
//	} else {	// 伪正解 - 好像就是正解 
	queue<int> q;	// 当前序列 
	priority_queue<int> hp; 
	
	for(int i = 1; i <= n; i++) {
		hp.push(a[i]);
	}
	
	while(q.size() < m) {
		int t = hp.top(); hp.pop();
		while(upbit(t) < upbit(q.front())) {
			int val = q.front(); q.pop();
			hp.push(val - (1 << upbit(val)));
		}
		q.push(t);
	}
	
	int ans = q.front();
	while(!q.empty()) {
		ans &= q.front();
		q.pop();
	}
	
	cout << ans << endl; 
//	}
	
	return 0; 
}
/* end - 10:16 |  */ 
