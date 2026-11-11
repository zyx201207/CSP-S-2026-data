#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans[300005];
bool f[300005];
stack<int> c;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){//第i轮游戏
		for (int j = i; j <= n; j++){//打出第j张牌
			if (!f[a[j]]){
				c.push(a[j]);
				f[a[j]] = true;
			}
			else{
				while(c.top() != a[j]){
					f[c.top()] = false;
					c.pop();
				}
			}
		}
		while (!c.empty()){ //结算 
			ans[c.top()]++;
			c.pop();
		}
		memset(f, 0, sizeof(f));
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
