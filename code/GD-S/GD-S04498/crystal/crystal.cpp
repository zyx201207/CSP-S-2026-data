#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5 * 1e5 + 5;
int n; ll m;
ll a[N];
ll s[N];
int ans = 0;
ll minx = 1e18;
bool cmp(ll x,ll y){
	return x < y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		minx = min(minx,a[i]);
	}
	for(int i = 1; i <= n; i++){
		a[i] += minx;
	}
	sort(a + 1,a + n + 1,cmp);
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i++){
		int l = 1,r = i - 1;
		int cnt = 0;
		while(l <= r){
			int mid = l + (r - l) / 2;
			ll ned = (ll)((i - 1) - mid + 1) * a[i];
			if(ned - (s[i - 1] - s[mid - 1]) <= m){
				r = mid - 1;
				cnt = mid;
			}else{
				l = mid + 1;
			}
		}
		ans = max(ans,i - cnt + 1);
	}
	printf("%d\n",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
