#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 7;
long long n, cnt;
int a[maxn];
char b[maxn];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
	}
	int i = 1, j = n;
	while(i <= j){
		if(b[i] == b[j] && a[i] > 0 && a[j] > 0){
			if(a[i] > a[j]){
				a[i] -= a[j];
				a[j] = 0;
			} else {
				a[j] -= a[i];
				a[i] = 0;
			}
		} else {
			cnt += min(a[i], a[j]);
			if(a[i] > a[j]){
				a[i] -= a[j];
				a[j] = 0;
			}else {
				a[j] -= a[i];
				a[i] = 0;
			}
		}
		if(a[i] <= 0)i++;
		if(a[j] <= 0)j--;
	}
	cout << cnt << endl;
	return 0;
}
