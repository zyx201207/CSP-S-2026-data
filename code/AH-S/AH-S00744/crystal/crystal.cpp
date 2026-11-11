#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int a[N];
int n, m;
int crystal[N];
bool check(int mid){  //use 'mid' crystals to make bigger one
	int num = crystal[mid];
	long long cnt = 0;
	for (int i = 1; i<=mid; i++){
		cnt += num-crystal[i];
	}
	if (cnt > m) return false;
	return true;
}
signed main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i<=n; i++){
		cin >> crystal[i];
	}
	
	sort (crystal+1, crystal+n+1);

	int l = 1, r = n, ans = -1e9;
	while (l <= r){
		int mid = (l+r)/2;
		if (check(mid)) ans = max(ans, mid), l = mid+1;
		else r = mid-1;
	}
	cout << ans;
}
