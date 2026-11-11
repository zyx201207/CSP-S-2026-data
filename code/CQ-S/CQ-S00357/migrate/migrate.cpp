#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e3+10;
ll c,t,n,d,s;
ll dis[N][N],x[N],cc[N][N];
void dfs(ll u,ll w,ll c){
	if(u==n+1)return ;
	for(ll i=u+1;i<=n;i++){
		if(w+x[i]-x[u]<=d){
			if(c<dis[s][i])cc[s][i]=1,dis[s][i]=c;
			else if(c==dis[s][i])cc[s][i]++;
			dfs(i,w+x[i]-x[u],c);
		}
		else{
			if(c+1<dis[s][i])cc[s][i]=1,dis[s][i]=c+1;
			else if(c+1==dis[s][i])cc[s][i]++;
			if(x[i]-x[u]<d)dfs(i,x[i]-x[u],c+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i];
		memset(dis,0x3f,sizeof dis);
		memset(cc,0,sizeof cc);
		for(ll i=1;i<=n;i++){
			s=i,dfs(i,0,1);
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(cc[i][j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
 0 2
 4 2
 1 2 3 4
 
 5 2
 1 2 3 4 5
*/

