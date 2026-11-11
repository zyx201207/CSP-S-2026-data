#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=1005;
vector<pair<int,int> > mp[N];
int c,n,m,d,q;
int w[M],k[N];
int l[M],a[M];
int dis[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>l[j];
			if(j>=2){
				for(int k=1;k<j;k++){
					//cout<<a[i][k]<<" "<<a[i][j]<<" "<<l[i][k]+l[i][j]<<'\n';
					mp[a[k]].push_back({a[j],l[k]+l[j]});
					mp[a[j]].push_back({a[k],l[k]+l[j]});
				}	
			}
		}
	}
	for(int st=1;st<=m;st++){
		for(int i=1;i<=m;i++){
			dis[st][i]=1e18;
		}
		dis[st][st]=0;
		priority_queue<pair<int,int> > qp;
		qp.push({0,st});
		while(!qp.empty()){
			int val=qp.top().first;
			int u=qp.top().second;
			//cerr<<"# "<<val<<' '<<u<<'\n';
			qp.pop();
			if(val!=dis[st][u]){
				continue;
			}
			for(pair<int,int> nw:mp[u]){
				int v=nw.first,w=nw.second;
				if(dis[st][v]>dis[st][u]+w){
					dis[st][v]=dis[st][u]+w;
					qp.push({dis[st][v],v});
				}
			}
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		cout<<dis[st][ed]+w[st]+w[ed]<<'\n';
	}
	return 0;
}
