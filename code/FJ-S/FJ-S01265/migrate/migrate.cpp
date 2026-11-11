#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,_,n,d,cnt,minn,arr[2000001],G[301][301],vis[301][301],f;
void dfs(int u,int v,ll sum){
	if(u==v){
		if(cnt==sum && !f) f=1;
		else f=0;
		cnt=min(cnt,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[u][i]){
			vis[u][i]=1;
			dfs(i,v,sum+G[u][i]);
			vis[u][i]=0;
		}
	} 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>_;
	while(_--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>arr[i];
		minn=arr[1];
		for(int i=2;i<=n;i++) minn=min(minn,arr[i]);
		if(d<minn) cout<<0<<endl;
		else if(c==11 || c==12){
			ll x=arr[2]-arr[1],cnt=0;
			while(d>=x){
				x+=arr[2]-arr[1];
				cnt++;
			}
			cout<<n-cnt-1<<endl;
		}else{
			ll ans=0;
			for(int i=1;i<n;i++){
				for(int j=1;j<=n-i;j++){
					if(arr[j+i]-arr[j]<=d) G[i][j+i]=G[j+i][i]=1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					memset(vis,0,sizeof(vis));
					f=0;
					cnt=0;
					dfs(i,j,0ll);
					if(f) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
