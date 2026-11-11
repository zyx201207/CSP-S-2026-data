#include<bits/stdc++.h>
#define int long long
using namespace std;
int dis[505][505],c,n,m,d,q,w[500005],k[505],cnt[500005];
vector<pair<int,int> >t[505];
pair<int,int> v[500005][20];
void ud(int &a,int b){a=min(a,b);}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int tmp,a;
			cin>>tmp>>a;
			t[i].push_back(make_pair(tmp,a));
			v[tmp][++cnt[tmp]]=make_pair(i,a);
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i!=j)dis[i][j]=1e18;
	for(int i=1;i<=m;++i)for(int j=1;j<=cnt[i];++j)for(int k=1;k<=cnt[i];++k)
		ud(dis[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)
		ud(dis[j][k],dis[j][i]+dis[i][k]);
	for(int i=1;i<=q;++i){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int i=1;i<=cnt[x];++i)for(int j=1;j<=cnt[y];++j)
			ud(ans,v[x][i].second+v[y][j].second+dis[v[x][i].first][v[y][j].first]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}