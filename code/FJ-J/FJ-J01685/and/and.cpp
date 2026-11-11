#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,b=0;
ll a[202202],flag[202202]= {0},c[202202];
void dfs(ll x,ll y) {
	y++;
	ll ans=c[1];
	if(x==0) {
		for(ll i=2; i<=m; i++) {
			ans=ans&c[i];
		}
		b=max(ans,b);
		return;
	}
	for(ll i=1; i<=n; i++) {
		if(flag[i]==0) {
			flag[i]=1;
			c[m-x+1]=a[i];
			dfs(x-1,y);
			flag[i]=0;
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(m,0);
	cout<<b;
	return 0;
}

