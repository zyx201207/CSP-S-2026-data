#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;
int a[N], l[N], r[N];
char c[N];

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n, sum = 0, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		l[i] = sum + 1;
		r[i] = sum + a[i];
		sum += a[i];
	}
	for(int i = 1, k = 0; k < (sum >> 1); i++){
		int rr = sum - l[i] + 1, ll = sum - r[i] + 1;
		int nl = 1, nr = n;
		while(nl < nr){
			int mid = nl + nr + 1 >> 1;
			if(l[mid] > ll){
				nr = mid - 1;
			} else {
				nl = mid;
			}
		}
		int s = nl;
		nl = 1, nr = n;
		while(nl < nr){
			int mid = nl + nr >> 1;
			if(r[mid] < rr){
				nl = mid + 1;
			} else {
				nr = mid;
			}
		}
		int e = nl;
		
		for(int j = e; j >= s; j--){
			if(c[i] == c[j]) continue;
			ans += min(rr, r[j]) - max(ll, l[j]) + 1;
		}
		
		k += a[i];
	}
	cout << ans;
}
/*
5
1 a
2 b
3 c
4 d
5 e
*/ 
