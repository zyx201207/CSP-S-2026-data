#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
typedef long long ll;
const ll inf=0x7f7f7f7f7f7f7f7f;
ll read(){
    ll s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s;
}
int n,m,d,q;
struct node{
	int id;
	ll cost;
};
vector<node> line[M];
ll dis[N][N],w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//double st=clock();
	read();
	n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int x=read();ll t=read();
			for(auto p:line[x]){
				int id=p.id;ll co=p.cost;
				dis[id][i]=dis[i][id]=min(dis[i][id],co+t);
			}
			line[x].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i||dis[i][k]==inf) continue;
			for(int j=1;j<=n;j++){
				if(k==j||i==j||dis[k][j]==inf) continue;
				dis[i][j]=min(dis[i][j],dis[k][j]+dis[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u=read(),v=read();
		if(u==v) cout<<0<<endl;
		ll ans=inf;
		for(auto x:line[u]){
			for(auto y:line[v]){
				if(dis[x.id][y.id]==inf) continue;
				ll dist=dis[x.id][y.id]+x.cost+y.cost+w[u]+w[v];
				ans=min(ans,dist);
			}
		}
		printf("%lld\n",ans);
	}
	//double ed=clock();
	//printf("%.0lfms",ed-st);
}
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
