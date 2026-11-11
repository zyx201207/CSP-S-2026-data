#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10,M=5e2+10,INF=0x3f3f3f3f3f3f3f3f;

int C,n,m,d,q;
long long w[N];
long long dis[M][M];
struct node{
	int id,num;
};
vector<node> sub[N];

void Floyd(){
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(node u1:sub[i]){
			for(node u2:sub[i]){
				if(u1.id==u2.id) continue;
				dis[u1.id][u2.id]=min(dis[u1.id][u2.id],1ll*u1.num+u2.num);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
//				if(dis[i][k]==INF||dis[k][j]==INF) continue;
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
}

signed main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int x,y,len;
	long long ans;
	for(int i=1;i<=n;i++){
		cin>>len;
		for(int j=1;j<=len;j++){
			cin>>x>>y;
			sub[x].push_back({i,y});
		}
	}
	
//	for(int i=1;i<=m;i++){
//		for(node u:sub[i]){
//			cout<<u.id<<" ";
//		}
//		cout<<endl;
//	}

	Floyd();
//	cout<<1;
	while(q--){
		cin>>x>>y;
		ans=LONG_LONG_MAX;
		for(node u1:sub[x]){
			for(node u2:sub[y]){
				ans=min(ans,dis[u1.id][u2.id]+u1.num+u2.num);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	
	return 0;
}
