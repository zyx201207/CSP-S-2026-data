#include <bits/stdc++.h>
using namespace std;
int n, m, mindex = 0, cnt = 0, x = 0, a[500010], table[500010][500010], index[500010];
bool in(int x){
	for (int i = 1; i <= n; i++){
		if (a[i] == x){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		mindex = 0;
		for (int k = i; k <= n; k++){
			if (!in(a[k])){
				table[i][++mindex] = a[k];
			}
			else{
				for (int j = k; j <= mindex; j++){
					table[i][j] = 0;
				}
				mindex = k;
				table[i][mindex] = a[k];
			}
		}
		index[x++] = mindex;
	}
	for (int i = 1; i <= n; i++){
		cnt = 0;
		for (int j = 1; j <= m; j++){
			for (int k = 1; k <= x; k++){
				if (j == table[i][k]){
				cnt++;
				}
			}
		}
		cout << cnt;
    }
	return 0;
}
