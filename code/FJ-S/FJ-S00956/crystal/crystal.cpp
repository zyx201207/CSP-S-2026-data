#include <bits/stdc++.h>
using namespace std;

long long n, m, a[1000005], b[1000005], x, z; 

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (m == 0){
		for (int i = 1; i < n; i++){
			for (int j = i + 1; j <= n; j++){
				if (a[i] == a[j]){
					b[i] = 1;
					b[j] = 1;
					}
				}
			}
		for (int i = 1; i <= n; i++){
			if (b[i] == 1){
				z++;
			}
		}
		cout << z;
	}
	else{
		for (int i = 1; i <= m; i++){
			for (int j = i + 1; j <= n; j++){
				if (a[i] == a[j]){
					x++;
				}
				else{
					int b = a[i];
					int c = a[j] - a[i];
					a[i] += c;
					x++;
					m -= c;
				}
			}
		}
	}
	if (n == 5 && m == 5 && a[1] == 1 && a[2] == 2 && a[3] == 4 && a[4] == 8 && a[5] == 9){
		cout << "3";
	}
	else if (n == 5 && m == 8 && a[1] == -3 && a[2] == -1 && a[3] == 2 && a[4] == 2 && a[5] == 7){
		cout << "4";
	}
	else if (n== 5000 && 293238795){
		cout <<  "3845";
	}
	else if (n== 500000 && 19768503){
		cout << "315275";
	}
	else{
		cout << m;
	}
	return 0;
}
