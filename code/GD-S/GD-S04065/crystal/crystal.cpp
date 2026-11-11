#include <bits/stdc++.h>
#define _for(i,a,b) for(int i = a,IM = b;i <= IM;i ++) 
using namespace std;
const int N = 5e5 + 9;
using ll = long long;
ll a[N],sum[N];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n; ll m; cin >> n >> m;
	_for(i,1,n) cin >> a[i];
	sort(a + 1,a + 1 + n);
	_for(i,1,n) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	_for(i,1,n) {
		int l = 1,r = i;
		while(l < r){
			int mid = l + r >> 1;
			if(1ll * (i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m)r = mid;
			else l = mid + 1;
		}
		ans = max(ans,i - l + 1);
	}
	cout << ans << '\n';
	
	return 0;
} 
