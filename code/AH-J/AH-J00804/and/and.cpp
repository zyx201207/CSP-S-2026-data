#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2000 + 10,M = 2 * 1e5 + 10;
ll n,m,a[N],ans;
bool vis[N];
void dfs(ll cur,ll sum){
	if(cur == m){
		ans = max(ans,sum);
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(cur + 1,sum & a[i]);
			vis[i] = 0;
		}
			
	}
}
struct Node {
	ll x,c;
}b[M];
ll check(ll x){
	ll cnt = 0;
	while(x){
		if(x & 1) cnt ++;
		x >>= 1;
	}
	 return cnt;
}
bool cmp(const Node& x,const Node& y){
	if(x.c != y.c) return x.c > y.c;
	else return x.x > y.x;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n <= 20){
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<=n;i++){
			vis[i] = 1;
			dfs(1,a[i]);
			vis[i] = 0;
		}
	} else if(n <= 2000){
		for(ll i=1;i<=n;i++) cin>>a[i];
		if(m == 1){
			for(ll i=1;i<=n;i++) ans = max(ans,a[i]);
		} else if(m == n){
			ans = a[1];
			for(ll i=2;i<=n;i++) ans &= a[i];
		} else {
			for(ll i=1;i<=n;i++)
				for(ll j=1;j<=n;j++){
					if(i == j) continue;
					ans = max(ans,a[i] & a[j]);
				}
		}
	} else {
		for(ll i=1;i<=n;i++) {
			cin>>b[i].x;
			b[i].c = check(b[i].x);
		}
		sort(b + 1,b + n + 1,cmp);
		ans = b[1].x;
		for(ll i=2;i<=m;i++) ans &= b[i].x;
	}
	cout<<ans;
	return 0;
}
