#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 5e5;
int n, m;
ll cnt[N + 3];
int a[N+ 3];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int cnta = 0, cntb = 0;
	if (n <= 5 && m <= 2){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				for (int w = j; w >= 1; w--){
					if (a[j] == a[w]) {
						for (int x = a[w] ;x < a[j]; x++){
							a[x] = 0;
						}
					}
				}
				
			}
			
			for (int j = 1; j <= n; j++){
				if (a[j] == 1){
					cnta++;
				}
				if (a[j] == 2){
					cntb++;
				}
			}
			
		}
		cout << cnta << " " << cntb << endl;
		return 0;
	}
	
	
	bool A = true;
	for (int i = 1; i < n; i++){
		if (a[i] >= a[i + 1]) A = false;
	}
	int rep = 0;
	if (A == true){
		for (int i = 1; i <= n; i++){
			if (a[i] == a[i + 1]){
				rep++;
			}
			for (int j =1; j <= m; j++){
				if (a[i] == j){
					cnt[j] += i;
				}
			}
		}
	}
	
	for (int i = 1; i <= m; i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
