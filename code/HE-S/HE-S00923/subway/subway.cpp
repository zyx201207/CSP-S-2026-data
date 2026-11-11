#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long dis[510][510],t[1010][510],w[500010],v;
vector<int> p[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("sumbway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c>=12){
		return 0;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			cin>>v;
			cin>>t[v][i];
			p[i].push_back(v);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=1e12;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(auto v:p[i]){
				if(t[v][j]){
					dis[i][j]=min(dis[i][j],t[v][i]+t[v][j]),dis[j][i]=dis[i][j];
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(k!=i && i!=j && k!=j && dis[k][i]+dis[j][k]<dis[i][j]) dis[i][j]=dis[j][i]=dis[k][i]+dis[j][k];
			}
		}
	}
	for(int x,y,i=1;i<=q;i++){
		cin>>x>>y;
		long long ans=1e16;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(t[x][i]&&t[y][j]) ans=min(ans,dis[i][j]+t[x][i]+t[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
