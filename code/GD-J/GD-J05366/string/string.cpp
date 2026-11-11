#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main (){
	preopen("string.in", "r", stdin);
	preopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	long long cnt = 0, l = 1, r = n;
	while (l != r){
		int x = min(a[l], a[r]);
		if (c[l] == c[r]){
			a[l] -= x;
			a[r] -= x;
			if (a[l] == 0){
				l++;
			}else {
				r--;
			}
		}else {
			cnt += x;
			a[l] -= x;
			a[r] -= x;
			if (a[l] == 0){
				l++;
			}else {
				r--;
			}
		}
	}
	cout << cnt;
}
