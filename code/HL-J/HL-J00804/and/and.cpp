#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,a[N],ans;
ll mand(ll a,ll b){
	if(a==0 || b==0) return (a^b);
	else return (a&b);
}
void dfs(ll t,ll l,ll sum){
	if(l==0){
		ans=max(ans,sum);
		return ;
	} 
	if(l>n-t+1){
		return ;
	}
	else if(l==n-t+1){
		ll x=sum;
		for(int i=t;i<=n;i++){
			x=mand(x,a[i]);
		}
		ans=max(x,ans);
		return ;
	}
	dfs(t+1,l-1,mand(sum,a[t]));
	dfs(t+1,l,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	dfs(1,m,0);
	cout << ans;
	return 0;
}                  