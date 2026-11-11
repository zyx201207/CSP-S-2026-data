# include <bits/stdc++.h>
using namespace std;


int a[(int)5e5];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m; cin >> n >> m;
	int i, j;
	for (i = 0; i < n; ++i){
		cin >> a[i];
	}
	if (n <= 5000 && m <= 3000){
		int bucket[m + 1], res[m];
		memset(res, 0, sizeof(int) * m);
		for (i = 0; i < n; ++i){
			memset(bucket, 0, sizeof(int) * (m + 1));
			for (j = i; j < n; ++j){
				if (bucket[a[j]]){
					int tmp = bucket[a[j]];
					for (int t = 0; t <= m; ++t){
						if (bucket[t] >= tmp){
							bucket[t] = 0;
						}
					}
				}
				bucket[a[j]] = j + 1;
			}
			for (j = 1; j <= m; ++j){
				res[j - 1] += (bool)bucket[j];
			}
		}
		for (i = 0; i < m; ++i){
			cout << res[i] << ' ';
		}
		return 0;
	}
	for (i = 0; i < m; ++i){
		cout << 1 << ' ';
	}
}

