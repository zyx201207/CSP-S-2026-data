#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N],ans[N];
unordered_set<int> st;
stack<int> stk;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			if(st.count(a[j])) {
				while(1) {
					if(stk.top() == a[j]) {
						stk.pop();
						break;
					}
					st.erase(stk.top());
					stk.pop();
				}
				stk.push(a[j]);
			} else {
				stk.push(a[j]);
				st.insert(a[j]);
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
