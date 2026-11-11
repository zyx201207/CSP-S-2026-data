#include<bits/stdc++.h>
using namespace std;
const int N=500+10;
const int M=5e5+10;
const long long INF=1e18;
typedef long long ll;
int s[N-5][M-5],n,m,c,dd,q,w[M],l,id,t,x,y,u,v;
ll d[N][N];
vector<int> idx[M];	//i地铁站所有经过的地铁编号
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&l);
		for(int j=1;j<=l;j++){
			scanf("%d%d",&id,&t);
			idx[id].push_back(i);
			s[i][id]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		int sz=idx[i].size();
		for(int j=0;j<sz;j++){
			for(int k=0;k<sz;k++){
				if(j==k) continue;
				u=idx[i][j],v=idx[i][k];
				d[u][v]=min(d[u][v],(ll)((ll)s[u][i]+(ll)s[v][i]));
			}
		}
	}
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][k]<INF&&d[k][j]<INF){
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
	}
	while(q--){
		ll ans=1e18;
		scanf("%d%d",&x,&y);
		for(int i=0;i<idx[x].size();i++){
			for(int j=0;j<idx[y].size();j++){
				u=idx[x][i],v=idx[y][j];
				ans=min(ans,d[u][v]+(ll)w[y]+(ll)w[x]+(ll)s[u][x]+(ll)s[v][y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
