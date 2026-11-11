#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
long long num[505][505];
vector<pair<int,int> > y[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1,k,a,t;i<=n;++i){
		cin>>k;
		while(k--){
			cin>>a>>t;
			y[a].push_back({i,t});
		}
	}
	memset(num,0x3f,sizeof num);
	for(int i=1;i<=n;++i) num[i][i]=0;
	for(int i=1;i<=m;++i)
		for(pair<int,int> u:y[i])
			for(pair<int,int> v:y[i])
				num[u.first][v.first]=min(num[u.first][v.first],(long long)u.second+v.second);
	for(int k=1;k<=n;++k)
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				num[j][i]=num[i][j]=min(num[i][j],num[i][k]+num[k][j]);
	while(q--){
		int u,v;
		cin>>u>>v;
		long long ans=1e18;
		for(pair<int,int> i:y[u])
			for(pair<int,int> j:y[v])
				ans=min(ans,num[i.first][j.first]+i.second+j.second);
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
