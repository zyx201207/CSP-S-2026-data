#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505,M=6e5+10,inf=1e18+10;

ll c,n,m,d,q,t,k,x,y,v[M],dist[N][N];
vector<pair<ll,ll> > e[M];

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	memset(dist,0x3f,sizeof dist);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>v[i];
	
	for(int i=1;i<=n;i++){
		
		cin>>k,dist[i][i]=0;
		for(int j=1;j<=k;j++) cin>>x>>t,e[x].push_back({i,t});
	}
	
	for(int i=1;i<=m;i++) for(int j=0;j<(ll)e[i].size();j++) for(int k=j+1;k<(ll)e[i].size();k++){
		
		ll opl=e[i][j].first,opr=e[i][k].first;
		dist[opl][opr]=min(dist[opl][opr],e[i][j].second+e[i][k].second);
		dist[opr][opl]=min(dist[opr][opl],e[i][j].second+e[i][k].second);
	}
	
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	
	while(q--){
		
		cin>>x>>y;
		ll ans=inf;
		
		for(int i=0;i<(ll)e[x].size();i++) for(int j=0;j<(ll)e[y].size();j++){
			
			ll opl=e[x][i].first,opr=e[y][j].first;
			ans=min(ans,e[x][i].second+e[y][j].second+dist[opl][opr]);
		}
		
		cout<<ans+v[x]+v[y]<<'\n';
	}
	
	return 0;
}

/*
15:30 meow!
*/
