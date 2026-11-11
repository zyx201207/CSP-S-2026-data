#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a[505][505],t[505][505],head[500005],cnt,vis[500005],dis[500005],st,ed;
struct yzx{
	int val,to,next;
};
yzx e[1000005];
priority_queue<pair<int,int>> Q;
queue <int>Q2;
void dijkstra(){
	for(int i=1;i<=m;i++){
		dis[i]=INT_MAX;
		vis[i]=0;
	}
	Q.push({0,st});
	dis[st]=0;
	while(!Q.empty()){
		int X=Q.top().second;
		Q.pop();
		if(vis[X]==1){
			continue;
		}
		vis[X]=1;
		for(int i=head[X];i;i=e[i].next){
			int Y=e[i].to,Z=e[i].val;
			if(dis[Y]>dis[X]+Z){
				dis[Y]=dis[X]+Z;
				Q.push({-dis[Y],Y}); 
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		} 
		for(int j=1;j<=k[i];j++){
			for(int o=j+1;o<=k[i];o++){
				e[++cnt].to=a[i][o];
				e[cnt].val=t[i][o]+t[i][j];
				e[cnt].next=head[a[i][j]];
				head[a[i][j]]=cnt;
				e[++cnt].to=a[i][j];
				e[cnt].val=t[i][j]+t[i][o];
				e[cnt].next=head[a[i][o]];
				head[a[i][o]]=cnt;
			}
		}
	}
	while(q--){
		cin>>st>>ed;
		long long ans=w[st]+w[ed];
		dijkstra();
		cout<<ans+dis[ed]<<'\n';
	}
}
