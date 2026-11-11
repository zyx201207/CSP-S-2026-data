#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e5 + 5;
int n, m;
int a[N];
int b[N];
bool vis[N];
long long ans = 0 - N;
void dfs (int cnt){
	if (cnt == m + 1){ // 选择m个数 
	    long long sum = b[1];
	    for (int i=1;i<=m;i++){
	    	sum = sum & b[i];
		}
		ans = max (ans, sum);
		return ;
	}
	for (int i=1;i<=n;i++){
		if (vis[i] == false){
			vis[i] = true;
			b[cnt] = a[i];
			dfs (cnt + 1);
			vis[i] = false;  // 简简单单回个溯 
		}
	}
}
int main(){
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen ("and.in ", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs (1);   
	cout << ans;
	// 不不不不，我无疑是愤怒的(O_O)?
	return 0;
}
