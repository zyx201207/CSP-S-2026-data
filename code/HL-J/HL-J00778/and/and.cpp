#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int A = 2e5+5;
ll a[A],n,m,vis[A],ans = 0;
bool cmp(ll a , ll b){
	return a > b;
}
void dfs(ll step,ll sum){
	if(step == m + 1){
		ans = max(ans , sum);
		return ;
	}
	for(int i = 1;i <= n;i ++){
		if(vis[i]) continue;
		vis[i] = 1;
		dfs(step + 1 , sum & a[i]);
		vis[i] = 0;
		dfs(step + 1 , sum);
	}
}
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	// 6号
	if(m == 1) {
		cout << a[1];
		return 0;
	}
	// 8 - 10
	if(m == 2){
	
		for(int i = 1;i <= n;i ++){
			for(int j = i + 1;j <= n;j ++){
				ans = max(ans , a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(m == n){
		for(int i = 2;i <= n;i ++)
		a[i] = a[i] & a[i-1];
		cout << a[n];
		return 0;
	}
	if(m == n-1){
		ll tmp = a[1];
		for(int i = 2;i <= n;i ++) tmp = tmp & a[i];
		for(int i = 1;i <= n;i ++){
			ans = max(ans , tmp|a[i]);
		}
		cout << ans << " ";
		return 0;
	}
	if(n<= 20){
		for(int i = 1;i <= n;i ++){
			vis[i] = 1;
			dfs(1 , a[i]);
		}
	}
	cout << ans;
	return 0;
}