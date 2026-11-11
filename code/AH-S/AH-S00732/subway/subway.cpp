#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cassert>
#define ll long long
#define pii pair<int,int> 
#define pli pair<long long,int>
#define pil pair<int,long long>
#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define oo 100000000000000000
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
ll w[M];
ll dis[N][N];
vector<pil>a[M];
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)if(i!=k){
			for(int j=1;j<=n;j++)if(i!=j&&j!=k){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=oo;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			ll y;
			cin>>x>>y;
			a[x].pb(mp(i,y));
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				int u=a[i][j].fr,v=a[i][k].fr;
				if(u>v) swap(u,v);
				dis[u][v]=min(dis[u][v],a[i][j].sc+a[i][k].sc);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++) dis[i][j]=dis[j][i];
	}
	Floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		ll res=oo;
		for(auto t1:a[x]){
			for(auto t2:a[y]){
				int id1=t1.fr,id2=t2.fr;
				res=min(res,dis[id1][id2]+t1.sc+t2.sc);
			}
		}
		cout<<res+w[x]+w[y]<<'\n';
	}
	return 0;
}


