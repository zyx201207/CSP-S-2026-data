#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
const long long inf=1e15+10;
int cnt[M],a[M][20],t[M][20],w[M],n,m,q;
long long v[N][N],dis[N][N];
bool vis[N];
struct eggy{
	int to;
	long long w;
	bool operator > (const eggy& tmp) const{
		return w>tmp.w;
	}
};
priority_queue<eggy,vector<eggy>,greater<eggy> > qu;
void dij(int st){
	memset(vis,false,sizeof(vis));
	dis[st][st]=0;
	qu.push({st,0});
	while(!qu.empty()){
		int u=qu.top().to;
		qu.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=1;i<=n;i++){
			if(i==u) continue;
			if(dis[st][i]>dis[st][u]+v[u][i]){
				dis[st][i]=dis[st][u]+v[u][i];
				qu.push({i,dis[st][i]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>n>>m>>q>>q;
	memset(v,0x3f,sizeof(v));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int x,y,k;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>x>>y;
			a[x][++cnt[x]]=i;
			t[x][cnt[x]]=y;
			for(int k=1;k<cnt[x];k++){
				if(v[i][a[x][k]]>y+t[x][k]){
					v[i][a[x][k]]=y+t[x][k];
					v[a[x][k]][i]=y+t[x][k];
				}
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dij(i);
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		long long mn=inf;
		for(int tx=1;tx<=cnt[x];tx++){
			for(int ty=1;ty<=cnt[y];ty++){
				mn=min(mn,dis[a[x][tx]][a[y][ty]]+t[x][tx]+t[y][ty]);
			}
		}
		cout<<mn+w[x]+w[y]<<"\n";
	}
	return 0;
}
//fc subwayt1.out subway1.ans
