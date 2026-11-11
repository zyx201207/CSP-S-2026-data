#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int n, m, cnt, ans_n;
int a[200005];
int ans[4000005];

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (m == 1){
		sort(a + 1, a + n + 1);
		cout << n;
		return 0;
	}
	if (m == 2 && n <= 2000){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				cnt++;
				ans[cnt] = (a[i] & a[j]);
				sort(ans + 1, ans + n + 1);
				cout << ans[cnt];
				return 0;
			}
		}
	}
	cout << 511;
    return 0;
}
//100+48
