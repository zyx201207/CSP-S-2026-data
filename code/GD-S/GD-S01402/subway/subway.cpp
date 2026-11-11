#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
ll dis[N][N],val[M];
vector<pair<int,ll>> sta[M];//站点x能到达哪些线及其用时 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>val[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		while(k--){
			int a;ll t;
			cin>>a>>t;
			sta[a].push_back({i,t});
		}
	}
	memset(dis,63,sizeof dis);
	for(int i=1;i<=m;i++){
		for(auto p1:sta[i]){
			for(auto p2:sta[i]){
				int l1=p1.first,l2=p2.first;
				if(l1==l2)continue;
				dis[l1][l2]=min(dis[l1][l2],p1.second+p2.second);
			}
		}
	} 
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll res=1e18;
		for(auto p1:sta[x]){
			for(auto p2:sta[y]){
				res=min(res,val[x]+val[y]+p1.second+p2.second+dis[p1.first][p2.first]);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
