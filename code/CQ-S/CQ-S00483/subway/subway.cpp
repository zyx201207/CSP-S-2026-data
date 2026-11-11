#include<bits/stdc++.h>
using namespace std;
int c,n,m,k,b,d,q,x,y,a[500005],h[500005],w[500005],nxt[500005],u[500005],v[500005];
long long dis[505][505],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q,memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k,dis[i][i]=0;
		for(int j=1;j<=k;j++){
			cin>>x>>y,nxt[w[x]]=++b,w[x]=b,u[b]=i,v[b]=y;
			if(!h[x]) h[x]=b;
		}
	}
	for(int i=1;i<=m;i++) for(int it=h[i];it;it=nxt[it]) for(int it2=nxt[it];it2;it2=nxt[it2]) dis[u[it]][u[it2]]=dis[u[it2]][u[it]]=min(dis[u[it]][u[it2]],(long long)v[it]+v[it2]);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		cin>>x>>y,ans=1e18;
		if(x==y){
			cout<<"0\n";
			continue;
		}
		for(int it=h[x];it;it=nxt[it]) for(int it2=h[y];it2;it2=nxt[it2]) ans=min(ans,dis[u[it]][u[it2]]+v[it]+v[it2]);
		cout<<ans+a[x]+a[y]<<'\n';
	}
	return 0;
} 
