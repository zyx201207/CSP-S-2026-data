#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 2e5 + 5;
int a[N];
int v[N];
int t[N];
int maxn;
void dfs(int s, int l){
	if(s == m + 1){
		int s = a[t[1]];
		for(int i = 2;i <= m;i++){
			s &= a[t[i]];
		}
		maxn = max(maxn, s);
		return ;
	}
	for(int i = l + 1;i <= n;i++){
		if(!v[i]){
			v[i] = 1;
			t[s] = i;
			dfs(s + 1, i);
			v[i] = 0;
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n>> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		for(int i = 1;i <= n;i++){
			maxn = max(maxn, a[i]);
		}
		cout << maxn;
	}else if(m == 2){
		int maxi = 0, maxj = 0;
		for(int i = 1;i < n;i++){
			for(int j = i + 1;j <= n;j++){
				int s = a[i] & a[j];
				maxn = max(maxn, s);
			}
		}
		cout << maxn;
	}else if(m == n){
		int maxn = a[1] & a[2];
		for(int i = 3;i <= n;i++){
			maxn &= a[i];
		}
		cout << maxn;
	}else if(m == n - 1){
		int s = a[1] & a[2];
		for(int i = 3;i <= n;i++){
			s &= a[i];
		}
		for(int i = 1;i <= n;i++){
			maxn = max(maxn, s | a[i]);
		}
		cout << maxn;
	}else if(n <= 20){
		dfs(1, 0);
		cout << maxn;
	}
	return 0;
}
