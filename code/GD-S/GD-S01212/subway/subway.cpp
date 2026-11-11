#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=510,M=5e5+10;
int n,m,cid,D,q; 
ll d[N][N],w[M]; 
vector<pair<int,ll>> v1[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>cid>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int len;cin>>len;
		while(len--){
			int x,y;cin>>x>>y;
			v1[x].push_back({i,y});
		}
	}
	memset(d,63,sizeof(d));
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto j:v1[i])for(auto k:v1[i])d[j.first][k.first]=min(d[j.first][k.first],j.second+k.second); 
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--){
		int u,v;cin>>u>>v;
		ll ans=d[0][0];
		for(auto i:v1[u])for(auto j:v1[v])ans=min(ans,d[i.first][j.first]+i.second+j.second);
		cout<<ans+w[u]+w[v]<<endl; 
	}
	
}

