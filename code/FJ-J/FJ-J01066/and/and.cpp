#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 10;
const int Log = 30;

int n, m, l, r;

int a[N], ans;

queue<int> q, p;

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	l = 1;
	r = n;
	
	for(int i = 1 ; i <= n ; i ++) 
		cin >> a[i];

	sort(a + 1, a + n + 1, cmp);
	
	for(int i = 1 ; i <= n ; i ++) 
		q.push(i);
	
	for(int i = Log ; i >= 0 ; i --) {
		int Q = q.size();
		for(int j = 1 ; j <= Q ; j ++) {
			if((a[q.front()] & (1 << i)) > 0) 
				p.push(q.front());			
			

			q.push(q.front());
			q.pop();
		}
		if(p.size() >= m) {
			ans += (1 << i);
			while(q.size()) q.pop();
			while(p.size()) {
				q.push(p.front());
				p.pop();
			}
		}
		while(p.size()) p.pop();
	}
	
	cout << ans;
	
	return 0;
}
