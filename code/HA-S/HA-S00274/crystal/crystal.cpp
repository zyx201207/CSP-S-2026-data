#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m, ans;
int a[N], qz[N];


signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	bool b = 1;
	int t;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == 2) t = a[2] - a[1];
		else if(i > 2){
			if(b == 1 && t != (a[i] - a[i - 1])) b = 0;
		}
	}
	
	t = abs(t);
	if(b == 1){
		int x = 0;
		for(int i = 1; i <= n; i++){
			if(m < (t * x)){
				cout << i - 1;
				return 0;
			}
			x += i;
		}
	}
	
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		qz[i] = qz[i - 1] + a[i];
	}
	

	int i = 1, ws = 2;
	for(int j = 2; j <= n; j++){
		int ws = j - i + 1;
		int t = a[j] * ws - (qz[j] - qz[i - 1]);
		if(t > m){
			i ++;
			j --;
			ws --;
			if(i >= n) break;
			continue;
		}
		ans = max(ans, ws);
		ws ++;
	}
	
	cout << ans;
	
	return 0;
}
