#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i = j;i <= k;i++)
typedef long long ll;
ll n,m;
ll arr[500005];
ll prefixarr[500005];
ll get_S(int l,int r){
	return arr[r]*(r-l+1)-(prefixarr[r]-prefixarr[l-1]);
}
int binary_search(int rw){
	int l = 1,r = rw,mid = (l+r) >> 1,ans = -1;
	while (l < r){
		mid = (l+r)>>1;
		if (get_S(mid,rw) <= m){
			r = mid;
			ans = mid;
		}
		else {
			l = mid+1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	rep(i,1,n){
		cin >> arr[i];
	}
	sort(arr+1,arr+n+1);
	prefixarr[0]=0;
	rep(i,1,n){
		prefixarr[i] = prefixarr[i-1]+arr[i];
	}
	int res = 0;
	rep(i,1,n){
		int left_bound = binary_search(i);
		if (left_bound != -1) res = max(res,i-left_bound+1);
	}
	cout << res;
	return 0;
} 
