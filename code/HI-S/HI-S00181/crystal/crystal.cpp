#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m;
int a[N];
bool check(int x) {
	int cnt = 0;
	for(int i=1; i<x; i++) {
		cnt += (a[x]-a[i]);
		if(cnt > m) return false;
	}
	return true;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1, a+n+1);
	int l = 1, r = n;
	while(l+1<r) {
		int mid = l + (r - l) /2 ;
		if(check(mid)) l = mid;
		else r = mid;
	}
	for(int i=l; i<=n; i++) {
		if(a[i] == a[l]) l = i;
	}
	cout<<l;
	return 0;
} 
