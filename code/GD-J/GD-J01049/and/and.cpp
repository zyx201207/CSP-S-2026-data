#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, m, a[N], b[N];
ll mx;
bool vis[N];
void dfs(int step){
	if(step == m){
		ll sum;
		for(int i = 2;i <= m;i++) sum += (b[i] ^ b[i - 1]);
		max(mx, sum);
		return;
	}
	for(int i = 0;i <= n;i++){
		vis[i] = 1;
		b[step] = a[i];
		if(!vis[step + 1]) dfs(step + 1);
		vis[i] = 0;
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];	
	}
	dfs(0);
	cout << mx;
	return 0; 
} 
