#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N = 2e5 + 1;
int n, m, a[N];
int ans, maxn;
bool vis[N], f;
void dfs(int step){
	if(step > n){
		if(!f){
			f = true;
			return;
		}
		int ans = 2147483647, cnt = 0;
		for(int i = 1; i <= n; i++){
			if(vis[i]){
				cnt++;
				ans &= a[i];
			}
		}
		if(cnt != m) return;
		maxn = max(maxn, ans);
		return;
	}
	vis[step] = false;
	dfs(step + 1);
	vis[step] = true;
	dfs(step + 1);
	vis[step] = false;
}
bool check1(){
	for(int i = 1; i <= n; i++){
		if(a[i] >= 4) return false;
	}
	return true;
}
bool check2(){
	for(int i = 1; i <= n; i++){
		int flag = false;
		for(int k = 1; k <= 30; k++){
			if(a[i] == (1 << k) - 1){
				flag = true;
				break;
			}
		}
		if(!flag) return false;
	}
	return true;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n <= 20){
		dfs(1);
		cout << maxn;
		return 0;
	}
	if(m == 1){
		maxn = 0;
		for(int i = 1; i <= n; i++){
			maxn = max(maxn, a[i]);
		}
		cout << maxn;
		return 0;
	}
	if(m == 2){
		maxn = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				maxn = max(maxn, (a[i] & a[j]));
			}
		}
		cout << maxn;
		return 0;
	}
	if(check1()){
		int i0, i1, i2, i3;
		i0 = i1 = i2 = i3 = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 0){
				i0++;
			}else if(a[i] == 1){
				i1++;
			}else if(a[i] == 2){
				i2++;
			}else if(a[i] == 3){
				i3++;
			}
		}
		if(m <= i3){
			cout << 3;
		}else if(m - i3 <= i2){
			cout << 2;
		}else if(m - i3 <= i1){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}
	if(check2()){
		sort(a + 1, a + n + 1);
		int i = n;
		int ans = a[n];
		for(int asd = 1; asd <= m; asd++){
			ans &= a[i];
			i--;
		}
		cout << ans;
		return 0;
	}
	return 0;
}
