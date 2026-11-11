#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 5 * 1e5 + 5;
bool all_same(int n, int a[]) {
	int num = 0;
	for(int i = 1; i < n; i++){
		if(a[i] == a[i - 1]) {
			num ++;
		}
	}
	if(num == n - 1) return 1;
	else return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, arr[maxn];
	ll m;
	cin >> n >> m;
	for(int j = 0; j < n; j++) cin >> arr[j];
	sort(arr, arr + n);
	int l = 0;
	while(!m <= 0){
		if(all_same(n, arr)) {
			break;
		}
		while(arr[0] != arr[l]) {
			arr[0] ++;
			m --;
		}
		sort (arr, arr + n);
		l = 0;
		while(arr[l] == arr[l + 1]) {
			l ++;
		}
		l ++;
//		for(int i = 0; i < n; i++) {
//			cout << arr[i];
//		}
	}
	int ans = 0;
//	sort (arr, arr + n);
	for(int i = 0; i < n - 1; i++) {
		if(arr[i] == arr[i + 1]) {
			ans ++;
		}
//		cout << arr[i] <<" " << arr[i + 1] << endl;
//		cout << ans  <<endl;
	}
	cout << ans + 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
