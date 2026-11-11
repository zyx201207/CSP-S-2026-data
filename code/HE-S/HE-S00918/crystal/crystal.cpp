#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
const int N = 5e5 + 50;

int a[N], sum[N];
int ans;

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)    cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i ++)   sum[i] = sum[i - 1] + a[i];
	for(int i = 1;i <= n;i ++){
		int k = a[i];
		int l = 1, r = i, ano = -1;
		while(l <= r){
			int mid = l + r >> 1;
			int nums = i - mid + 1; 
			if(k * nums - (sum[i] - sum[mid - 1]) <= m){
				ano = nums;
				r = mid - 1;
			}
			else   l = mid + 1;
		}
		ans = max(ans, ano);
	}
	cout << ans;
}
