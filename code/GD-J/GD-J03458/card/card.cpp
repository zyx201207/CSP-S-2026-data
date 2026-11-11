#include<bits/stdc++.h>
using namespace std;

int n, m, a[500010], stk[500010], ds[300010], top = 1;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int k = 1; k <= n; k ++){
		stack<int> stk; 
		for(int i = k; i <= n; i ++){
			if(stk.empty()) stk.push(a[i]);
			else if(stk.top() == a[i]) continue;
			else stk.push(a[i]);
		}
		bool vis[3010];
		memset(vis, false, sizeof(vis));
		while(!stk.empty()){
			if(!vis[stk.top()]){
				vis[stk.top()] = true;
				ds[stk.top()] ++;
			}
			stk.pop();
		}
	}
	for(int i = 1; i <= m; i ++){
		cout << ds[i] << ' ';
	}
	return 0;
}
