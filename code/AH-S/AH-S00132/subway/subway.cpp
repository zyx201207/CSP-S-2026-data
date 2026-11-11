#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long ti;
	int h;
};
int c,n,m,u,q;
int w[500010];
long long d[510][510];
vector<Node>e[500010];
void Flood(){
	for(int i=1;i<=n;i++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				d[x][y]=min(d[x][y],d[x][i]+d[i][y]);
			}
		}
	}
}
vector<int>f[500010];
unordered_map<int,long long>mp[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>u>>q;
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)d[i][i]=0;
    for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int s;
			long long l;
			cin>>s>>l;
			for(auto v:e[s]){
				d[v.h][i]=min(d[v.h][i],v.ti+l);
				d[i][v.h]=min(d[i][v.h],v.ti+l);
			}
			e[s].push_back({l,i});
			f[s].push_back(i);
			mp[s][i]=l;
		}
	}
	Flood();
        while(q--){
		int a,b;
		cin>>a>>b;
		long long ans=1e18;
		for(int x:f[a]){
			for(int y:f[b]){
				ans=min(ans,d[x][y]+mp[a][x]+mp[b][y]);
			}
		}
		cout<<ans+1ll*w[a]+1ll*w[b]<<'\n';
	}
    return 0;
}
