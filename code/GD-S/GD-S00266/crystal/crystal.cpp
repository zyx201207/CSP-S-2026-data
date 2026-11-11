#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n,m,a[N],sum[N],ans;

bool check(int l,int r){
	return (((r - l + 1) * a[r] -  (sum[r] - sum[l - 1])) <= m);
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + a[i];
	}
	
	for(int i = 2; i <= n; i++){
		int l = 1, r = i - 1;
		while(l <= r){
			int mid = (l+r)>>1;
			if(check(mid,i)) { r = mid - 1; }
			else l = mid + 1;
		}
		ans = max(ans,i - l + 1);
	}
	
	cout<<ans;
	return 0;
} 
