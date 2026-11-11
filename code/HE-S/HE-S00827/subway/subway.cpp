#include<bits/stdc++.h>
using namespace std;
struct Node{
	int id,v;
};
vector<Node> s[500005],G[500005],g[500005];
int c,n,m,d,q,w[500005],dis[1000][1000];
vector<int> S[1000],T[1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k,a,t;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d %d",&a,&t);
			s[a].push_back(Node{i,t});
		}
	}
	memset(dis,0x3f3f3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
		if(s[i].size()>1){
			for(int x=0;x<s[i].size();x++){
				for(int y=0;y<s[i].size();y++){
					if(x!=y){
						dis[s[i][x].id][s[i][y].id]=s[i][x].v+s[i][y].v;
					}
				}
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
	while(q--){
		int x,y;
		int ans=1e9+7;
		cin>>x>>y;
		for(int i=0;i<s[x].size();i++){
			for(int j=0;j<s[y].size();j++){
				ans=min(ans,w[x]+w[y]+dis[s[x][i].id][s[y][j].id]+s[x][i].v+s[y][j].v);
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
