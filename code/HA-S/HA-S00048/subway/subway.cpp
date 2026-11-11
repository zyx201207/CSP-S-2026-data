#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],dis[505][505];
map<int,int>mp[505];
vector<short>vt[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			mp[i][a]=t;
			vt[a].emplace_back(i);
			
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		for(short&h:vt[i]){
			for(short&g:vt[i]){
				if(h!=g){
					dis[h][g]=min(dis[h][g],mp[h][i]+mp[g][i]);
					dis[g][h]=dis[h][g];
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=k&&j!=k&&i!=j){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					dis[j][i]=dis[i][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=1145141919810000;
		for(short&h:vt[x]){
			for(short&g:vt[y]){
				if(h==g){
					ans=mp[h][x]+mp[g][y];
				}
				else{
					ans=min(ans,dis[h][g]+mp[h][x]+mp[g][y]);
				}
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}//200pts