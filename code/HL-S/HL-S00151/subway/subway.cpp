#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1010;
const ll MAX=1e18;
ll c,n,m,d,q;
ll w[N],k[N];
ll a[N][N],t[N][N];
ll vis[N][N];
ll r[N][N];
ll x,y;
ll ans;
void dfs(ll cnt,ll now,ll y){
	if(now==y){
		ans=min(cnt,ans);
		return ;
	}
	else{
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(vis[i][j]==1){
					for(int u=1;u<=k[j];u++){
						if(a[j][u]!=i&&!r[j][u]){
							r[j][u]=1;
							dfs(cnt+1,a[j][u],y);
							r[j][u]=0;
						}
					}
				}
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			vis[a[i][j]][i]=1;
		}
	}
	while(q--){
		cin>>x>>y;
		ans=MAX;
		ll sum=0;
		sum+=w[x];
		sum+=w[y];
		dfs(0,x,y);
		ans++;
		sum+=ans*t[1][1]*2;
		cout<<sum<<endl;
	}
	//bushi,zen me zuo a qwq
	return 0;
}

