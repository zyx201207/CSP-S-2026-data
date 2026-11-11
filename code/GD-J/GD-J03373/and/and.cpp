#include <bits/stdc++.h>
using namespace std;

int ans = -1;
int n, m, a[200005];
bool chos[25];
int num1(int a){
	int cnt = 0;
	while(a > 0){
		if((a & 1)) cnt++;
		a >> 1;
	}
	return cnt;
}
bool cmp(int a, int b){
	return a > b;
}
void srch(int k){
	if(k == n + 1){
		int t, cnt = 0;
		bool f = true;
		for(int i = 1;i <= n;i++){
			if(chos[i]){
				if(f) t = a[i], f = false;
				else t &= a[i];
				cnt++;
			}
		}
		if(cnt == m && t > ans) ans = t;
		return;
	}
	chos[k] = true;
	srch(k + 1);
	chos[k] = false;
	srch(k + 1);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	if(n <= 20){
		srch(1);
		cout << ans;
	}
	else if(m == n){
		ans = a[1];
		for(int i = 2;i <= n;i++){
			ans = (ans & a[i]);
		} 
		cout << ans;
	}
	else if(m == 2 && n <= 2000){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j) continue;
				if((a[i] & a[j]) > ans) ans = (a[i] & a[j]);
			}
		}
		cout << ans;
	}
	else if(m == 1 && n <= 2000){
		for(int i = 1;i <= n;i++){
			if(a[i] > ans) ans = a[i];
		}
		cout << ans;
	}
	else{
		sort(a + 1, a + n + 1, cmp);
		ans = a[1];
		for(int i = 2;i <= m;i++) ans = (ans & a[i]);
		cout << ans;
	}
	return 0;
}

