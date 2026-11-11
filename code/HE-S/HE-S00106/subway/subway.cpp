#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=520,M=5e5+10;
const ll inf=0x7f7f7f7f7f7f7f7f;
int w[M];
int tak[N][M];
int c,n,m,d,q,k;
ll dis[N][N];
vector<pair<int,int> > sta[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			tak[i][a]=t;
			sta[a].push_back({i,t});
		}
	}
	memset(dis,0x7f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(auto j:sta[i]){
			for(auto p:sta[i]){
				int a=j.first,b=p.first;
				int va=j.second,vb=p.second;
				if(a==b) dis[a][b]=0;
				else dis[a][b]=min(dis[a][b],1ll*va+vb);
			}
		}
	}
	for(int p=1;p<=n;p++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][p]!=inf&&dis[p][j]!=inf) dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<'\n';
			continue;
		}
		ll ans=inf;
		int a1=0,a2=0;
		for(auto i:sta[x]){
			for(auto j:sta[y]){
				int a=i.first,b=j.first;
				if(dis[a][b]<ans){
					ans=dis[a][b];
					a1=a;a2=b;
				}
			}
		}
		cout<<ans+1ll*tak[a1][x]+tak[a2][y]+w[x]+w[y]<<'\n';
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
