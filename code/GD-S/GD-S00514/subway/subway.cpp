#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int a[N];
int t1[N];
int f[600][600];
int ans;
int flag;
struct edge{
	int id,t;
};
map<int,edge>idch;
int idji[N];
vector<edge>e[N];
vector<int>rnk[N];
map<int,int>t2[N];
int chg[N],cnt;
int w;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&t1[i]);
	for(int i=1;i<=n;i++){
		cin>>w;
		for(int j=1;j<=w;j++){
			cin>>a[j]>>t2[a[j]][i];
			rnk[a[j]].push_back(i);
			if(!idji[a[j]]){
				idch[a[j]]={i,t2[a[j]][i]};
				idji[a[j]]=1;
			}else{
				if(idji[a[j]]==1)e[a[j]].push_back({idch[a[j]].id,idch[a[j]].t});
				idji[a[j]]++;
				chg[++cnt]=a[j];
				e[a[j]].push_back({i,t2[a[j]][i]});
			}
		}
	}
	memset(f,0x3f3f3f3f,sizeof f);
	for(int i=1;i<=cnt;i++){
		for(auto u:e[chg[i]]){
			for(auto v:e[chg[i]]){
				if(u.id==v.id)continue;
				f[u.id][v.id]=u.t+v.t;
				f[v.id][u.id]=f[u.id][v.id];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)f[i][j]=0;
				else f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		ans=1e18;
		int x,y;
		scanf("%lld%lld",&x,&y);
		for(int i=0;i<rnk[x].size();i++){
			for(int j=0;j<rnk[y].size();j++){
				ans=min(ans,f[rnk[x][i]][rnk[y][j]]+t2[x][rnk[x][i]]+t2[y][rnk[y][j]]);
			}
		}
		ans+=t1[x]+t1[y];
		printf("%lld\n",ans);
	}
} 
