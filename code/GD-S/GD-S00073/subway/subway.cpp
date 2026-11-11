#include<bits/stdc++.h>
#define ll long long
#define mkp make_pair
using namespace std;
const int N=505,M=500010;
const ll inf=1e18;
int c,n,m,d,q,st,ed;
ll ans,w[M],e[N][N];
vector<pair<int,ll>> v[M];
void chkmin(ll &x,ll y){
	x=min(x,y);
}
int main(){
//	system("fc subway.out subway7.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k,x,y;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&x,&y);
			v[x].push_back(mkp(i,y));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) e[i][j]=inf;
			else e[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)v[i].size();j++){
			for(int k=j+1;k<(int)v[i].size();k++){
				ll t=v[i][j].second+v[i][k].second;
				chkmin(e[v[i][j].first][v[i][k].first],t);
				chkmin(e[v[i][k].first][v[i][j].first],t);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	while(q--){
		scanf("%d%d",&st,&ed);
		ans=inf;
		for(auto i:v[st]){
			for(auto j:v[ed]){
				ans=min(ans,w[st]+w[ed]+i.second+j.second+e[i.first][j.first]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
