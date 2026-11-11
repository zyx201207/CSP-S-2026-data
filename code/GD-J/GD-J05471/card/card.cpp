#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 5e5+5;

int n, m, a[maxn], stk[maxn], ans[maxn], cnt[maxn];
bool vis[maxn] = {0};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	for(int k = 1; k <= n; k++){
		int top = 0;
		for(int i = k; i <= n; i ++){
			while(top > 0 && vis[a[i]] && stk[top] != a[i]){
				vis[stk[top--]] = 0;
			}
			if(top == 0 || stk[top] != a[i]) {
				stk[++top] = a[i];
			}
			vis[a[i]] = 1;
//			for(int j = 1; j <= top; j++) cout << stk[j] << " ";
//			cout << "\n";
		}
//		cout << "\n";
		for(int j = 1; j <= m; j++) {
			if(vis[j]) ans[j]++;
			vis[j] = 0;
		}
	}
	for(int i = 1;i <= m; i++) cout << ans[i] << " ";
	return 0;
}



/*
      _|          _|_|_|
     _|_|       _|      _|
    _|  _|     _|        
   _|    _|    _|       
  _|_|_|_|_|   _|        _|
 _|        _|   _|      _|
_|          _|    _|_|_|
*/

