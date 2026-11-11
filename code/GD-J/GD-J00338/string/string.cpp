#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2e5 + 10;
int n, len;
int len1, len2;
int Ans;
int a[MAX], Sum[MAX];
char c[MAX];

int find(int l, int r, int tar) {
	int res = l;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(Sum[mid] < tar) {
			res = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return res;
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		len += a[i];
		Sum[i] = Sum[i - 1] + a[i];
	}
	
	for(int i = 1; i <= len / 2; i++) {
		int res = find(1, n, i);
		int res1 = find(1, n, n - i + 1);
		if(c[res + 1] != c[res1]) {
			Ans++;
		}
	}
	
	cout << Ans;
//	int l = 1, r = n;
//	while(l < r) {
//		if((l == r - 1 || l == r + 1) && c[l] == c[r]) break;
//		if(c[l] != c[r]) {
//			if(a[l] < a[r]) {
//				Ans += a[r] - a[l];
//				a[r] -= a[l];
//				l++;
//			}
//			else if(a[l] > a[r]) {
//				Ans += a[l] - a[r];
//				a[l] -= a[r];
//				r--;
//			}
//			else {
//				Ans += a[l];
//				l++, r--;
//			}
//		}
//		else {
//			Ans += min(a[l], a[r]);
//			if(a[l] < a[r]) {
//				a[r] -= a[l];
//				l++;
//			}
//			else if(a[l] > a[r]) {
//				a[l] -= a[r];
//				r--;
//			}
//			else {
//				l++, r--;
//			}
//		}
//	}
	

	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b

