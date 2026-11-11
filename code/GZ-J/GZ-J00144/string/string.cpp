//GZ-J00144  张心恬  贵阳市白云区华师一学校 
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2e5 + 10;
int n, l = 1, r;
long long a[N], ans;
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	r = n;
	for (int i = 1; i <= n; i ++ ){
		cin >> a[i] >> c[i];
	}
	while (l < r){
		if (c[l] == c[r]){
			if (a[l] == a[r]){
				l ++ ;
				r -- ;
				continue;
			}
			else{
				if (a[l] <= a[r]){
					a[r] -= a[l];
					l ++ ;
				}
				else{
					a[l] -= a[r];
					r -- ;
				}
			}
		}
		else{
			if (a[l] <= a[r]){
				a[r] -= a[l];
				ans += a[l];
				l ++ ;
			}
			else{
				a[l] -= a[r];
				ans += a[r];
				r -- ;
			}
		}
	}
	cout << ans;
	return 0;
} 
