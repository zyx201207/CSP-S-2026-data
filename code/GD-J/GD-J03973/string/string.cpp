#include <bits/stdc++.h>
using namespace std;
int n;
__int128 sum, tt;
struct T1 {
	int num;
	char now;
}a[200005];
void coutt(__int128 k) {
	if(k > 0) {
		coutt(k / 10);
		putchar(k % 10 + '0');
	}
	return;
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> a[i].num >> a[i].now, tt += a[i].num;
	tt /= 2;
	int i = 0;
	int j = n + 1;
	while(i < n && j > 1 && i < j - 1) {
		i++;
		j--;
		if(a[i].num > a[j].num) {
			int t = a[i].num;
			while(t >= a[j].num && j > 0) {
				if(a[i].now != a[j].now) sum += a[j].num;
				t -= a[j].num;
				j--;
			}
			a[j].num -= t;
			if(a[i].now != a[j].now) sum += t;
			j++;
		}
		else {
			int t = a[j].num;
			while(t >= a[i].num && i <= n) {
				if(a[i].now != a[j].now) sum += a[i].num;
				t -= a[i].num; 
				i++;
			}
			a[i].num -= t;
			if(a[i].now != a[j].now) sum += t;
			i--;
		}
	}
	coutt(sum);
	return 0;
}
