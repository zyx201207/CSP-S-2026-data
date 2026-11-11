#include <bits/stdc++.h>
using namespace std;
#define int long long
#define D(a) cout << #a << " : " << a << " "
#define nl cout << "\n"
const int N = 5e5 + 10;
int n,m;
int a[N],p[N];
int res;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) p[i] = p[i-1] + a[i];
	for (int i=1;i<=n;i++){
		int l = 1,r = i,ans = i;
		while (l <= r){
			int mid = (l + r) / 2;
			if ((i - mid + 1) * a[i] - (p[i] - p[mid-1]) <= m){
				ans = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		res = max(res,i-ans+1);
	}
	cout << res;
	return 0;
}
