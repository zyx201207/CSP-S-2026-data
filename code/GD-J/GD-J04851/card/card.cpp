#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010], b[300010];
stack<int> st;
bool f[300010];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	bool flag = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] < a[i - 1]) flag = 0;
	}
	if (n * n <= 20000000){
		for (int i = 1; i <= n; i++){
			memset(f, 0, sizeof(f));
			while(!st.empty()){
				st.pop();
			}
			for (int j = i; j <= n; j++){
				if (f[a[j]] == 1){
					while(st.top() != a[j]){
						f[st.top()] = 0;
						st.pop();
					}
					f[a[j]] = 1;
				}
				else{
					st.push(a[j]);
					f[a[j]] = 1;
				}
			}
			for (int j = 1; j <= m; j++){
//				cout << f[j] << ' ';
				b[j] += f[j];
			}
//			cout << '\n';
			
		}
		for (int i = 1;i <= m; i++){
			cout << b[i] << ' ';
		}
		return 0;
	}
	if (flag){
		for (int i = 1; i <= n; i++){
			if (a[i] != a[i + 1]) b[i] += i;
		}
		for (int i = 1; i <= m; i++){
			cout << b[i] << ' ';
		}
		return 0;
	}
}
