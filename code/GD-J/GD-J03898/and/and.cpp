#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
ll n,m,a[maxn],maxx=-1;
void dfs(ll x,ll c,ll ans){
	//cout<<ans<<" "<<maxx<<endl;
	if(c==m){
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=x+1;i<=n;i++){
		if(ans&a[i]<=maxx)continue ;
		dfs(i,c+1,ans&a[i]);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,INT_MAX);
	cout<<maxx;
	return 0;
}
//Trick||Treat!
