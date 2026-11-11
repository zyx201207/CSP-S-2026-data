#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5+3;
int arr[maxn],pre[maxn];
int n,m;
void solve1_bl(){
	int ans = -1ll;
	for(int i = 1;i <= n;i++){
		int tot = 0ll;
		int res = 0ll;
		for(int j = i-1;j >= 1;j--){
			tot += arr[i]-arr[j];
			if(tot > m) break;
			else res = max(res,i-j+1);
		}
		ans = max(ans,res);
	}
	cout << ans << '\n';
}
void solve2_dt1(){
	int ans = 0ll;
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i-1] + (i-1);
		if(pre[i] <= m) ans = max(ans,i);
	} 
	cout << ans << '\n';
}
void solve3_dtk(int delta){
	int ans = 0ll;
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i-1] + (i-1);
		if(pre[i]*delta <= m) ans = max(ans,i);
 	}
 	cout << ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> arr[i];
	sort(arr+1,arr+n+1);
	bool book1 = 1,book2 = 1;
	int dt = arr[2]-arr[1];
	for(int i = 1;i < n;i++){
		if(arr[i+1]-arr[i] != dt){
			book1 = 0;
			book2 = 0;
			break;
		}
	}
	if(dt != 1) book1 = 0;
	if(n <= 5000){
		solve1_bl();
		return 0;
	}else if(book1 == 1){
		solve2_dt1();
		return 0;
	}else if(book2 == 1){
		solve3_dtk(dt);
		return 0;
	}
	return 0;
}