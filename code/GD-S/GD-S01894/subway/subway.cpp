#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,m,d,q,w[500010],k,x,wx,dis[510][510],dis1[510][510],vis[510],y;
vector<pair<int,int> >vc[500010];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>wx;
			vc[x].push_back({i,wx});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vc[i].size();j++){
			for(int k=j+1;k<vc[i].size();k++){
				int x=vc[i][j].first,y=vc[i][k].first,wx=vc[i][j].second,wy=vc[i][k].second;
				dis[x][y]=min(dis[x][y],wx+wy);
				dis[y][x]=dis[x][y];
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis1[i][j]=1e18;
			vis[j]=0;
		}
		dis1[i][i]=0;
		for(int k=1;k<=n;k++){
			int mx=1e18,rt=0;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&dis1[i][j]<mx){
					rt=j;
					mx=dis1[i][j];
				}
			}
			if(rt==0)break;
			vis[rt]=1;
			for(int j=1;j<=n;j++){
				if(rt!=j&&dis[rt][j]!=1e18&&dis1[i][j]>dis1[i][rt]+dis[rt][j]){
					dis1[i][j]=dis1[i][rt]+dis[rt][j];
				}
			}
		}
	}
	while(q--){
		cin>>x>>y;
		int ans=1e18;
		for(int i=0;i<vc[x].size();i++){
			for(int j=0;j<vc[y].size();j++){
				int xx=vc[x][i].first,yy=vc[y][j].first,wx=vc[x][i].second,wy=vc[y][j].second;
				if(xx>yy)swap(xx,yy);
				if(dis1[xx][yy]!=1e18){
					ans=min(ans,dis1[xx][yy]+wx+wy);
				}
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
}
