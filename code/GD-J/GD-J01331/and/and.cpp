#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll a[N],n,m;
ll ans;
bool st;
vector<ll> g;
void dfs(ll q,ll cnt){
	if(cnt>=m){
		ll t=a[g[0]];
		for(int i=1;i<g.size();i++) t=t&a[g[i]];
		ans=max(t,ans);
		return ;
	}
	for(int i=q;i<=n;i++){
		g.push_back(i);
		dfs(i+1,cnt+1);
		g.pop_back();
	}
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<ans;
	
	return 0;
}
