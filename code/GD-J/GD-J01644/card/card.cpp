#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	cin.tie (nullptr) -> sync_with_stdio (false);
	cin >> n >> m;
	vector <int> a (n + 1), b (n + 1);
	for (int i = 1; i <= n; i++){
		cin >> a [i];
	}
	for (int i = 1; i <= n; i++){
		vector <int> vis (m + 1, -1);
		for (int j = i; j <= n; j++){
			if (vis [a [j]] == -1){
				vis [a [j]] = j;
			}
			else {
				for (int k = vis [a [j]] + 1; k < j; k++){
					vis [a [k]] = -1;
				}
				vis [a [j]] = j;
			}
		}
		for (int j = 1; j <= m; j++){
			if (vis [j] != -1){
				b [j]++;
			}
		}
	}
	for (int i = 1; i <= m; i++){
		cout << b [i] << " ";
	}
	return 0;
}
