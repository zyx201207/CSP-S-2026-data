#include <bits/stdc++.h>
using namespace std;

long long nn, m, n[500010], q[500010], ans, f;

void add(){
	for (int j = f; j < nn; j++){
			n[j] = 0;
			for (int k = 1; k <= f; k++){
				for (int v = k; v >= 1; v--){
					n[j] += q[j - v + 1];
				}
			}
			
			//cout << n[j] << ' ';
			if (m >= n[j]){
				ans = f + 1;
				return;
			}
		}
	return;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> nn >> m;
	cin >> n[0];
	for (int i = 1; i < nn; i++){
		cin >> n[i];
	}
	sort(n, n + nn);
	for (int i = 1; i < nn; i++){
		q[i] = n[i] - n[i - 1];
	}
	for (int i = 1; i < nn; i++){
		f = i;
		add();
		
		//cout << endl;
		if (ans == i - 2){
			break;
		}
	}
	cout << ans;
	return 0;
}
