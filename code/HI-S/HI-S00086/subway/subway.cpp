#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t;
int w[500005],dp[5005][5005],dis[5005],vis[5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c == 0||c == 7||c == 8||c == 9||c == 10||c == 11){
		for(int i = 1;i<=m;i++){
			cin>>w[i];
		}
		int x,y,v1,v2,ux,uy;
		memset(dp,0x3f,sizeof(dp));
		for(int i = 1;i<=n;i++){
			cin>>t;
			cin>>x>>v1>>y>>v2;
			dp[x][y] = v1+v2;
			dp[y][x] = v1+v2;
		}
		for(int i = 1;i<=q;i++){
			cin>>ux>>uy;
			memset(vis,0,sizeof(vis));
			memset(dis,0x3f,sizeof(dis));
			dis[ux] = 0;
			for(int i = 1;i<=n;i++){
				int minid = 0x3f3f3f3f,id;
				for(int j = 1;j<=n;j++){
					if(vis[j] == 0&&dis[j]<minid){
						minid = dis[j];
						id = j;
					}
				}
				vis[id] = 1;
				for(int j = 1;j<=n;j++){
					if(vis[j] == 0&&dis[id]+dp[id][j]<dis[j]){
						dis[j] = dis[id]+dp[id][j];
					}
				}
			}
			if(dis[uy] >= 0x3f3f3f3f){
				cout<<w[ux]+w[uy]<<endl;
			}else{
				cout<<w[ux]+w[uy]+dis[uy]<<endl;
			}
			
		}
	}
	return 0;
}
