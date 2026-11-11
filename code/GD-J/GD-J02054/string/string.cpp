#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
long long a[N];
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	long long s = 0;
	int l = 1, r = n;
	while(l < r){
		if(a[l] > a[r]){
			if(c[l] != c[r]){
				s += a[r];
				a[l] = a[l] - a[r];
				r--;
			} else {
				a[l] = a[l] - a[r];
				r--;
			}
		}else if(a[l] == a[r]){
			if(c[l] != c[r]){
				s += a[l];
				l++;
				r--;
			} else {
				l++;
				r--;
			}
		} else {
			if(c[l] != c[r]){
				s += a[l];
				a[r] = a[r] - a[l];
				l++;
			} else {
				a[r] = a[r] - a[l];
				l++;
			}
		}
	}
	cout << s;
	return 0;
}
