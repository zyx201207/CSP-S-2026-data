#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(#s ".in","r",stdin)
#define out(s) freopen(#s ".out","w",stdout)
#define int long long
const int N = 5e5+5, inf = 0x3f3f3f3f3f3f3f3f;

int n,m;
int arr[N];
int sum[N];
int ans;

inline bool check(int x,int y){
	return arr[y]*(y-x+1) <= m+sum[y]-sum[x-1];
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	in(crystal);
	out(crystal);
//	scanf("%lld%lld",&n,&m);
	cin >> n >> m;
//	for(int i=1;i<=n;i++)	scanf("%lld",&arr[i]);
	for(int i=1;i<=n;i++)	cin >> arr[i];
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++)	sum[i] = sum[i-1]+arr[i];
	for(int i=1;i<=n;i++){
		int L = 1, R = i, mid, ans_ = i;
		while (L <= R){
			mid = (L+R)>>1;
			if (check(mid,i))	R = mid-1, ans_ = mid;
			else			L = mid+1; 
		}
		ans = max(ans,i-ans_+1);
	}
	printf("%lld",ans);
	return 0;
}
/*

5 8
-3 -1 2 2 7

*/
