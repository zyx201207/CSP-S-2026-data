#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e5+10;
long long n,m,a[N] = {},sum[N] = {};
int search(int p){
	int l = 1,r = p,mid;
	while (l < r){
		mid = (l+r) >> 1;
		long long t = a[p] * (p-mid+1) - (sum[p]-sum[mid-1]);
		if (t <= m) r = mid;
		else l = mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++) sum[i] = sum[i-1] + a[i];
	int maxn = 0;
	for (int i = 1;i <= n;i++) maxn = max(maxn,i-search(i)+1);
	cout << maxn;
	return 0;
}
