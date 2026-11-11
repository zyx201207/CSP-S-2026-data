#include<bits/stdc++.h>
using namespace std;
long long n,m,c,d,q,dis[510][510],w[500010],a,b,x,y,K,ans;
struct aty{
	long long id,t;//这个点有哪几条线经过，和转站时间 
};
vector<aty> E[500010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
			if(i==j) dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>K;
		for(int j=1;j<=K;j++){
			cin>>a>>b;
			E[a].push_back({i,b});
		}
	}
	
	for(int i=1;i<=m;i++){
		for(aty j:E[i]){
			for(aty k:E[i]){
				dis[j.id][k.id]=min(dis[j.id][k.id],j.t+k.t);
				dis[k.id][j.id]=dis[j.id][k.id];
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
/*	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
		}
	}*/
	for(int Q=1;Q<=q;Q++){
		cin>>x>>y;
		ans=1e18;
		for(aty i:E[x]){
			for(aty j:E[y]){
				ans=min(ans,i.t+j.t+dis[i.id][j.id]);
			}
		} 
		ans=ans+w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
} 
