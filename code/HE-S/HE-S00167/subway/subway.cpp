#include<bits/stdc++.h>
using namespace std;
#define int long long
int _,n,m,d,q,w[500005],e[505][505],E[1005][1005];
vector<pair<int,int> > vc[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,t;j<=k;j++) cin>>x>>t,vc[x].push_back({i,t});
	}//O(¡Æk)=5e5
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) e[i][j]=(i==j?0:1e18);
	//O(n^2)=2.5e4
	for(int i=1;i<=m;i++){
		for(int j=0;j<vc[i].size();j++){
			for(int k=0;k<j;k++){
				int u=vc[i][j].first,v=vc[i][k].first,w=vc[i][j].second+vc[i][k].second;
				e[u][v]=e[v][u]=min(e[u][v],w);
			}
		}
	}//O(m*d^2)=2e8
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	//O(n^3)=1.25e8
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=1e18;
		for(int i=0;i<vc[u].size();i++){
			for(int j=0;j<vc[v].size();j++){
				int wu=vc[u][i].second,s=vc[u][i].first;
				int wv=vc[v][j].second,t=vc[v][j].first;
				ans=min(ans,w[u]+wu+e[s][t]+wv+w[v]);
			}
		}
		cout<<ans<<endl;
	}//O(q*d^2)=4e7
	return 0;
}//subway 32pts
//#4: 2.5s;  #5: 2.1s;  #6: 3s;  #7: 3.3s;  #rand: 3.9s,  ´ýÓÅ»¯ 
//O(¡Æk+n^2+m*d^2+n^3+q*d^2)=3.5e8
//#1~#3:8046
//#4~#6:327800
//#7,#8:8280400
//#9~#11:165651000
//#12~#15:134070000
//#16~#19:365750000
//#20,#21:240500012
//#22,#23:128150000
//#24,#25:365750000
