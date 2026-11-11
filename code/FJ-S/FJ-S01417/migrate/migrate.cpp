#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;
ll c,t,n,d,a[N],ans,md;
void dfs(ll l,ll r,ll tim,ll &res){
	if(l==r){
		if(tim==md) res++;
		else if(tim<md){
			res=1;
			md=tim;
		}
		return ;
	}
	for(int i=l+1;i<=r;i++)
	if(a[i]-a[l]<=d) dfs(i,r,tim+1,res);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n-2;i++)
		for(int j=i+2;j<=n;j++){
			ll res=0;
			md=1e18;
			dfs(i,j,0,res);
			if(res==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
