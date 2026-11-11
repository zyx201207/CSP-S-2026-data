#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=500+10,M=5000+10;
int c,n,m,d,q,w[M],k[N];
vector<pii> g[M];
ll dis[M][M];
void gx(int st){
	for(int i=1;i<=n;i++){
		ll mii=dis[st][g[i][0].first]+g[i][0].second;
		for(int j=1;j<g[i].size();j++){
			int u=g[i][j].first,w=g[i][j].second,lst=dis[st][u];
			mii=min(lst+1ll*w,mii);
			dis[st][u]=min(dis[st][u],mii+w);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//freopen("subway1.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	if(m>400) return 0;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,b;
			cin>>a>>b;
			g[i].push_back(pii{a,b});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
		for(int j=1;j<m;j++){
			gx(i);
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<1ll*w[x]+1ll*w[y]+dis[x][y]<<'\n';
	}
	return 0;
}
