#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 5e5 + 10, maxv = 3e5 + 10;

int n, m, a[maxn], d[maxn], ans1[maxn], pre[maxn];
bool vis[maxv]; 

stack<int> stk;

map<int, int> mp;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mp[a[i]] = max(i, mp[a[i]]);
	}
	
	for(int i = n; i >= 1; i --){
		if(vis[a[i]]){
			d[i] -= i;
			d[mp[a[i]]] += i;
		}else{
			vis[a[i]] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + d[i];
	}
	
	for(int i = 1; i <= n; i++){
		ans1[a[i]] = max(ans1[a[i]], min(pre[i], i));
	}
	
	for(int i = 1; i <= m; i++){
		cout << ans1[i] << ' ';
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
