#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=2e4+10;
//hope 50pts
int c,n,m,d,q,k,dis[N][N],w[N];
struct poi{
	int u,w;
};
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++){
		cin>>k;
		vector<poi> vec;
		while(k--){
			int a,t;
			cin>>a>>t;
			vec.push_back({a,t});
			for(poi st:vec){
				dis[st.u][a]=min(dis[st.u][a],t+st.w);
				dis[a][st.u]=min(dis[a][st.u],t+st.w);
			}
		}
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(i!=k&&j!=k&&i!=j)
					dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+dis[x][y]+w[y]<<endl;
	}
	return 0;
} 
