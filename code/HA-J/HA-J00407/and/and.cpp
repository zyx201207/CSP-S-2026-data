#include<bits/stdc++.h>
using namespace std;
#define int long long

int cnt[40], d[6];
void js(){
	int a = 1;
	for(int i = 0; i <= 32; i++){
		cnt[i] = (a - 1);
		a *= 2;
	}
}

const int N = 2e5 + 10;
int n, m;
int a[N];

int dfs(int w, int t){
	if(t >= m || w > n) return 0;
	if(t == m - 1) return a[w];
	int ans = 0;
	for(int i = w + 1; i <= n; i++){
		ans = max(ans, a[w] & dfs(i + 1, t + 1));
	}
	return ans;
}


signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	js();
	cin >> n >> m;
	int sum = 0;
	bool b = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		int t = 0;
		if(b == 1 && a[i] <= 4){
			d[a[i]] ++;
		}
		else b = 0;
		while(a[i] >= cnt[t]){
			if(a[i] == cnt[t]){
				sum ++;
				break;
			}
			t ++;
		}
	}
	
	if(b == 1){
		if(d[4] >= m) cout << 4;
		else if(d[3] >= m) cout << 3;
		else if((d[2] + d[3]) >= m) cout << 2;
		else if((d[1] + d[2] + d[3]) >= m) cout << 1;
		else cout << 0;
		return 0;
	}
	
	if(n == sum){
		sort(a + 1, a + n + 1);
		cout << a[n - m + 1];
		return 0;
	}
	
	if(m == 1){
		sort(a + 1, a + n + 1);
		cout << a[n];
		return 0;
	}
	
	if(m == 2){
		int _max = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				_max = max(_max, a[i] & a[j]);
			}
		}
		cout << _max;
		return 0;
	}
	
	if(m == n){
		int ans = a[1];
		for(int i = 2; i <= n; i++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	
	if(m == (n - 1)){
		int ans, _ans = 0;
		for(int i = 1; i <= n; i++){
			if(i == 1) ans = a[2];
			else ans = a[1];
			for(int j = 1; j <= n; j++){
				if(i == j) continue;
				ans &= a[j];
			}
			_ans = max(_ans, ans);
		}
		cout << _ans;
		return 0;
	}
	
	if(n <= 20){
		cout << dfs(1, 0);
		return 0;
	}
	
	cout << 1;
	return 0;
}





