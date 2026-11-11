#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long a[200005],ans = 0;
	int n;
	char b[200005];
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= n; ++i){
		ans += a[i];
	}
	int l = 1,r = n;
	long long num = ans / 2;
	for (int i = 1; i <= ans / 2; i++){
		if (a[l] == 0) l++;
		if (a[r] == 0) r--;
		if (b[l] == b[r]){
				num--;
		}
		a[l]--;
		a[r]--;
	}
	cout << num;
	return 0;
}
