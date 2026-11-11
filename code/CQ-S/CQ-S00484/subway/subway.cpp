#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,a[500005];
ll dis[505][505];
vector<pair<int,int> > vec[505];
vector<pair<int,int> > Ins[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++) {
			int u,w;cin>>u>>w;
			vec[i].push_back({u,w});
			Ins[u].push_back({i,w});
		}
	}memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){	
		dis[i][i]=0;
		for(auto k:vec[i]){//5e5
			for(auto j:Ins[k.first]){//20
				if(i==j.first) continue;
				dis[i][j.first]=dis[j.first][i]=min(dis[i][j.first],(ll)k.second+(ll)j.second);
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int u,v;cin>>u>>v;ll ans=1e18;
		for(auto i:Ins[u]) for(auto j:Ins[v]) ans=min(ans,dis[i.first][j.first]+(ll)i.second+(ll)j.second);
		cout<<ans+(ll)a[u]+(ll)a[v]<<'\n';
	}
	return 0;
}
/*
把每个线路看成一个点，所以点与点之间只连1条边，然后枚举d^2，这波操作牛不牛不逼

但是如何点与点之间找到最小代价边呢？n^2d有点牛逼 

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

