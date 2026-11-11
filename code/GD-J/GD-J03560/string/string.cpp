#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];
char c[maxn];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	while (l <= r){
		//cout << l << " " << r << " " << a[l] << " " << a[r] << endl;
		if (c[l] != c[r]){
			ans += min(a[l], a[r]);
			//cout << ans << " ";
		}
		if (a[l] >= a[r]){
			a[l] -= a[r];
			r--;
		}
		else if (a[l] < a[r]){
			a[r] -= a[l];
			l++;
		}
	}
	cout << ans;
	return 0;
}

//11:07 AC! 100pts
