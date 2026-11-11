#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

int val[500005];
int n, m;

bool check(int l, int r){
	return val[r] - val[l-1] + m >= (val[r] - val[r-1]) * (r - l + 1);
}

int bs(int i){
	int l = 1, r = i, ans = i;
	while(l <= r){
		int mid = (r + l) / 2;
		if(check(mid, i)) ans = mid, r = mid-1;
		else l = mid+1;
	}
	return i - ans + 1;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> val[i];
	sort(val+1, val+1+n);
	int maxv = 0;
	for(int i = 1; i <= n; i ++) val[i] += val[i-1], maxv = max(maxv, bs(i));
	cout<<maxv<<endl;
} 