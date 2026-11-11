#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
int c, t;
int n, d;
long long a[(int)2e6 + 5], b[(int)2e6 + 5];
long long cnt;

int main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	for (int q = 1; q <= t; q++){
		cin >> n >> d;
		for (int j = 1; j <= n; j++){
			cin >> a[j];
			b[j] = a[j] - a[j-1];
		}
		
		for (int i = 1; i <= n; i++){
			if (b[i] == 1){
				if (n - i + 1 >= 4 && b[i + 1] == n / 2 && b[i + 2] == n / 2 && b[i + 3] == n / 2){
					cnt++;
					int j = 1;
					while (j <= i && b[i - j] == d){
						cnt++;
						j++;
					}
					j = 1;
					while (i + j < n && b[i + j] == d){
						cnt++;
						j++;
					}
				}
			}
		}
		
		cout << cnt;
		cnt = 0;
	}
	
	return 0;
}

