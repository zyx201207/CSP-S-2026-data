#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 2e5 + 10;
const int T = int(pow(2, 20)) - 1;
long long a[N];
int endmax = -1;
int f(int m, int n){
	int a[10000], b[10000], c[10000];
	int cnt1 = 0, cnt2 = 0;
	while(m){
		a[++cnt1] = m % 2;
		m /= 2;
	}
	while(n){
		b[++cnt2] = n % 2;
		n /= 2;
	}
	int t = 0;
	for(int i = 1; i <= max(cnt1, cnt2); i++){
		if(a[i] == b[i] && (a[i] != 0 && b[i] != 0)){
			c[t++] = 1;
		}else{
	
			c[t++] = 0;
			
		}
	}
	int ea = 0;
	for(int i = 0; i <= t; i++){
		if(c[i]) {
			ea += int(pow(2, i));
		}
	}
	
	return ea;
}
void dfs(int dep, int ans, int cnt){
	
	if(dep == m + 1){
		endmax = max(endmax, ans);
		return;
	}
	if(cnt == n + 1){
		return;
	}
	dfs(dep + 1, f(ans, a[cnt]), cnt + 1);
	dfs(dep, ans, cnt + 1);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}

	dfs(0, T, 1);
	cout<<endmax;
	return 0;
}