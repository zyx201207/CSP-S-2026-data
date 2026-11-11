#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[1000005],a[1005][1005],k[1000005],t[1005][1005],x,y,ans;
void dfs(ll z,ll p,ll tm,ll zz){
	if(p>k[z]) return;
	if(a[z][p]==y){
		ans=min(ans,tm);
		return;
	}
	if(a[z][p+1]==y) dfs(z,p+1,tm+w[y]+t[z][p+1],-1);
	else dfs(z,p+1,tm,-1);
	for(ll i=1;i<=n;i++){
		if(i==z||i==zz) continue;
		for(ll j=1;j<=k[i];j++){
			if(a[i][j]==a[z][p]){
				dfs(i,j,tm+t[z][p]+t[i][j],z);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		ans=1e9;
		cin>>x>>y;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=k[i];j++){
				if(a[i][j]==x){
					dfs(i,j,w[a[i][j]]+t[i][j],-1);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

