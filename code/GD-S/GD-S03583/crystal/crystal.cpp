#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
//注意到：对于每一个数字，可以改变几个点可以logN计算
//暴力枚举每一个点NlogN即可 
int n;
ll m, a[N], s[N];
int find(int x){
	int l = 1, r = x;
	while(l < r){
		int mid = (l + r) / 2;
		if(a[x] * (x - mid + 1) - s[x] + s[mid - 1] <= m) r = mid;
		else l = mid + 1;
	}
	return l;
}
int main(){//O(NlogN) 100pts 20min
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i ++) s[i] = s[i - 1] + a[i];
	int ans = 0;
	for(int i = 1;i <= n;i ++) ans = max(ans, i - find(i) + 1);
	cout << ans;
	return 0;
}
