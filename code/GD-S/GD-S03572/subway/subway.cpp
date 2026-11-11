#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q;
ll w[500005];

struct xian{
	ll a[20005];
	ll dp[20005];
	ll id;
}x[505];
ll vis[505][20005],ans;
void dfs(ll o,ll p,ll sum,ll l,ll r){
	for(int i=1;i<=x[o].id;i++){
		if(vis[o][i]!=1){
			vis[o][i]=1;
			if(x[o].dp[i]==r){
				
				ans=min(ans,sum+x[o].a[i]+w[l]+w[r]);
				//return;
			}else{
				for(int ii=1;ii<=n;ii++){
					for(int jj=1;jj<=x[ii].id;jj++){
						if(x[ii].dp[jj]==x[o].dp[i]&&vis[ii][jj]!=1){
							vis[ii][jj]=1;
							dfs(ii,jj,sum+x[ii].a[jj]+x[o].a[i],l,r);
							vis[ii][jj]=0;
						}
					}
				}
			}
			vis[o][i]=0;
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		x[i].id=k;
		for(int j=1;j<=k;j++){
			cin>>x[i].dp[j]>>x[i].a[j];
		}
	}
	while(q>0){
		q-=1;
		ll l,r;
		ans=1e18;
		cin>>l>>r; 
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=x[i].id;j++){
				if(x[i].dp[j]==l){
					vis[i][j]=1;
					dfs(i,j,x[i].a[j],l,r);
					vis[i][j]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
