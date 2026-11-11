#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
typedef long long ll;
ll n,m;
ll a[N];
ll ans=1;
void dfs(int x,ll sum,ll tg){
	 
	if(x==n){
		ans=max(ans,sum);
		return;
	}
	if(n-x<m-tg)return;
	if(tg==1)sum=a[x];
	dfs(x+1,sum,tg);
	tg++;
	dfs(x+1,sum&a[x],tg);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;	
}
