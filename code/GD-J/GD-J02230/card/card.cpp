#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn];
bool b[5050];
int cnt[maxn];
stack<int> stk;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++){
		memset(b, false, sizeof(b));
		for (int j = i; j <= n; j ++){
			int tmp = a[j];
			if (b[tmp]){
				while(!stk.empty()){
					if (stk.top() == tmp){
						break;
					}
					stk.pop();
				}
			} else {
				b[tmp] = true;
				stk.push(tmp);
			}
		} 
		while(!stk.empty()){
			cnt[stk.top()] ++;
			stk.pop();
		}
	} 
	for (int i = 1; i <= m; i ++){
		cout << cnt[i] << " ";
	}
	cout << '\n';
	return 0;
} 
