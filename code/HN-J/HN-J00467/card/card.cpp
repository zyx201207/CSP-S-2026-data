#include <bits/stdc++.h>
using namespace std;

int a[500005], cnt[300005];
stack <int> stk;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		int b[300005] = {0};
		for(int j = i; j <= n; j++){
			if(b[a[j]] == 1){
				while(stk.top() != a[j]){
					stk.pop();
				}
				stk.pop();
			}
			b[a[j]] = 1;
			stk.push(a[j]);
		}
		while(!stk.empty()){
			cnt[stk.top()]++;
			stk.pop();
		}
	} 
	for(int i = 1; i <= m; i++){
		cout << cnt[i] << ' ';
	}
	
	return 0;
} 

