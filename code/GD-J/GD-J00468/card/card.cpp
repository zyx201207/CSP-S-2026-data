#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500010];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >>n >>m;
	bool fl = 1; // ÅÐ¶ÏA 
	for(int i = 1; i <= n; i++) {
		cin >>a[i];
		if(a[i] < a[i-1]) {
			fl = 0;
		}
	}
	if(n <= 5000 && m <= 3000) {
		int nxt[5010] = { };
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(a[i] == a[j]) {
					nxt[i] = j;
					break;
				}
			}
		}
		int ans[3010] = { };
		for(int i = 1; i <= n; i++) {
			bool vis[3010] = { };
			for(int j = i; j <= n; ) {
				if(nxt[j] == 0 && vis[a[j]] == 0) {
					vis[a[j]] = 1;
					ans[a[j]] += 1;
					j++;
					continue;
				}
				else if(nxt[j] != 0) {
					j = nxt[j];
					continue;
				}
				j++;
			}
		}
		for(int i = 1; i <= m; i++) {
			cout <<ans[i] <<" ";
		}
		return 0;
	}
	if(fl) {
		int b[200010] = {}, ans[100000] = {};
		b[1] = a[1];
		int pri = 1;
		for(int i = 2; i <= n; i++) {
			if(a[i] != a[pri]) {
				pri++;
				a[pri] = a[i];
			}
		}
		for(int i = 1; i <= pri; i++) {
			ans[b[i]] = i;
		}
		for(int i = 1; i <= m; i++) {
			cout <<ans[i] <<" ";
		}
		return 0;
	}
}
