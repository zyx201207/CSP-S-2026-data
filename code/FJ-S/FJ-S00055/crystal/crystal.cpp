#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a[500010], ans = 1, sum;
bool ok1 = true, ok2 = true;

signed main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != i)ok1 = false;
	}
	if(ok1){
		int cnt = 0, w = 0;
		for(int i = 0; ; ){
			if(i > m){
				cout << cnt << "\n";
				return 0;
			}
			cnt++;
			//cout << i << "\n";
			w++;
			i += w;
		}
	}
	
	sort(a + 1, a + n + 1);
	int c = a[2] - a[1];
	for(int i = 3; i <= n; i++){
		if(a[i] - a[i - 1] != c){
			ok2 = false;
			break;
		}
	}
	
	if(ok2){
		int cnt = 0, w = 0;
		for(int i = 0; ; ){
			if(i > m){
				cout << cnt << "\n";
				return 0;
			}
			cnt++;
			//cout << i << "\n";
			w += c;
			i += w;
		}
	}
	
	for(int i = 1; i <= n; i++){
		int now = 0;
		for(int len = 2; i + len - 1 <= n; len++){
			int j = i + len - 1;
			now = now + (a[j] - a[j - 1]) * (len - 1);
			if(now <= m)ans = max(ans, j - i + 1);
			
		}
	}
	cout << ans << "\n";
	
	return 0;
}
