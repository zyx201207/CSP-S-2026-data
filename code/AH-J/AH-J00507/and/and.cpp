#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans;
ll l,r;
void dfs(ll m1,ll k){
	if(m1 == 0){
		cout << ans;
		return;
	}
	ll a1 = ans;
	ans = max(ans,((a[k])&(a[k+1])));
	if(a1 != ans){
		m1--;
	}
	dfs(m1,k+1);
	
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n;i++)cin >> a[i];
	dfs(m,0);
	return 0;
}
