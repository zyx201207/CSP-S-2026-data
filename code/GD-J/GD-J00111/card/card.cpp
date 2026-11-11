#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5, M = 3e5+5;
int a[N], cnt[M];
bool vis[M];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++ ) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		stack<int> st;
		for (int j = i; j <= n; j++){
			if (vis[a[j]] == 0) {
				st.push(a[j]);
				vis[a[j]] = 1;
			}
			else {
				while(!st.empty() && st.top() != a[j]){
					vis[st.top()] = 0;
					st.pop();
				}	
			}
		}
		while(!st.empty()){
			cnt[st.top()]++;
			st.pop();
		} 
	}
 	
 	for (int i = 1;i <= m; i++) cout << cnt[i] << ' ';
	
	return 0;
} 
