#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N =2e5+10;
ll n, m, a[N], ans;
bool A = true;
void dfs(ll i, ll d, ll sum){
	
	
	if(d >= m){
		ans = max(sum, ans);
		return;
	}
	
	if(i > n) return;
	dfs(i+1,d,sum);
	if(sum==0) sum=a[i];
	dfs(i+1,d+1,sum&a[i]);
	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(ll i=1; i<= n; ++i) cin >> a[i];
	
	if(m==1){
		for(ll i=1; i<= n; ++i){
			ans = max(ans, a[i]);
		}
	
	}else if(m==n){
		ans = a[1];
		for(ll i=2; i<= n; ++i){
			ans &= a[i];
		}
	}else if(m==2){
		for(ll i=1; i<= n; ++i){
			for(ll j=i+1; j<= n; ++j){
				ans = max(ans,a[i]&a[j]);
			}
		}
	}else if(n <= 20){
		dfs(1,0,0);
	}else{
		sort(a+1,a+n+1);
		ans = a[n-m+1];
	}
	
	cout <<ans;
	return 0;
	
	
}
