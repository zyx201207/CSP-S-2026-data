#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N = 5e5+9;
int a[N];
__int128 pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) pre[i] = pre[i-1] + a[i];
	int ans = 1;
	for(int i = 1;i <= n;i++){
		int l = 1,r = i - 1,res = -1;
		while(l <= r){
			int mid = (l + r) / 2;
			__int128 cost = a[i] * (i - mid) - (pre[i-1] - pre[mid-1]);
			if(cost <= m) r = mid - 1,res = mid;
			else l = mid + 1;
		}
		if(res != -1){
			ans = max(ans,i - res + 1); 
		}
	}
	cout<<ans;
	return 0;
} 
