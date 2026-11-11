#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n;
long long m;
long long a[N], f[N][N], b[N][N], ans;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			f[i][j] = a[i] - a[j];
			b[i][j] = b[i][j - 1] + f[i][j];
		}
    }
    for(int i = 1; i <= n; i++){
		for(int j = i; j >= 0; j--){
			if(b[i][i] - b[i][j] == m){
				if(ans < (long long)i - j + 1){
					ans = (long long) i - j;
				}
			}
			
		}
	}
	cout << ans;
    return 0;
}
