#include<bits/stdc++.h>
using namespace std;
stack <int> s;
int a[100086], ans[100086] = {0};

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	for(int i = 1; i <= n; i++) {	
		int vis[100086] = {0};
		for(int j = i; j <= n; j++) {
			if(vis[a[j]] == 0) {
				s.push(a[j]);
				vis[a[j]]++;
			}
			else {
				while(s.top() != a[j]) {
					vis[s.top()] = 0;
					s.pop();
				}
			}
		}
		while(!s.empty()) {
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i = 1; i <= n; i++) {
		if(ans[i] != 0) cout << ans[i] << ' '; 
	}
	return 0;
} 
