#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node {
	long long num;
	char c;
}a[N];
long long n, sum, cnt, s, l, r, p;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].num >> a[i].c;
		sum += a[i].num;
	}
	bool flag = 0;
	long long t;
	for(int i = 1; i <= n; i++) {
		if(s + a[i].num == sum / 2) {
			p = i + 1;
			break;
		}
		if(s + a[i].num > sum / 2) {
			p = i;
			t = s + a[i].num - sum / 2;
			a[i].num -= t;
			flag = 1;
			break;
		}
		s += a[i].num;
	}
	if(flag || sum & 1) {
		for(int i = n; i >= p+1; i--) {
			a[i+1].num = a[i].num;
			a[i+1].c = a[i].c;
		}
		a[p+1].num = t;
		a[p+1].c = a[p+2].c;
	}
	l = 1, r = p;
	while(l < r && l <= p && r <= n){
		if(a[l].c != a[r].c) {
			cnt += min(a[l].num, a[r].num);
		}
		if(a[l].num < a[r].num) a[r].num -= a[l].num, l++;
		else if(a[l].num == a[r].num) l++, r++;
		else a[l].num -= a[r].num, r++;
	}
	cout << cnt;
	return 0;
} 
