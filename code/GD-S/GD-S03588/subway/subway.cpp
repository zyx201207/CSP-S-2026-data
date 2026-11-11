#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
typedef long long ll;
ll g[N][N],w[M];
ll c,n,m,d,q;
int D[M],now[M],siz[N];
pair<int,ll>mem[M],mem2[M],*s[N],*bs[M];
void Floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				g[j][i]=g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
ll _min(ll&x,ll y){return(x=min(x,y));}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	system("fc subway7.ans subway.out");
	 freopen("subway.in","r",stdin);
	 freopen("subway.out","w",stdout);
	// freopen("subway.out","w",stdout);
	s[0]=mem;
	memset(g,1,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>siz[i];
		s[i]=s[i-1]+siz[i-1];
		for(int j=0;j<siz[i];j++)
			cin>>s[i][j].first>>s[i][j].second,
			D[s[i][j].first]++;
	}
	bs[0]=mem2;
	for(int i=1;i<=m;i++)
		bs[i]=bs[i-1]+D[i-1];
	for(int i=1;i<=n;i++)
		for(int j=0;j<siz[i];j++){
			bs[s[i][j].first][now[s[i][j].first]]={i,s[i][j].second};
			now[s[i][j].first]++;
		}
	for(int i=1;i<=m;i++)
		for(int j=1;j<D[i];j++)
			for(int k=0;k<j;k++)
				g[bs[i][k].first][bs[i][j].first]=
				_min(g[bs[i][j].first][bs[i][k].first],
					bs[i][j].second+bs[i][k].second);
//	for(int i=1;i<=m;i)
	Floyd();
	while(q--){
		int x,y;
		ll ans=g[0][0];
		cin>>x>>y;
		for(int i=0;i<D[x];i++)
			for(int j=0;j<D[y];j++)
				ans=min(ans,g[bs[x][i].first][bs[y][j].first]+bs[x][i].second+bs[y][j].second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
//	out.close();
//	system(("fc subway.out "+str+".ans").c_str());
	return 0;
}
