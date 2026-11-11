#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int a[N], n;
ll m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1, a + n + 1);
	int l = 1;
	ll tot = 0;
	int res = 0;
	for(int i = 2;i <= n;i++){
		tot += 1ll * (a[i] - a[i-1]) * (i - l);
		while(tot > m){
			tot -= a[i] - a[l++];
		}
		res = max(res, i - l + 1);
	}
	cout<<res;
}
// 最后一舞，afo 快乐 
