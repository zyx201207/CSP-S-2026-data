#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=509,M=2e4+9;
int c,n,m,d,q,k[N],a[N][M],x[N],y[N],t[N][M];
ll w[M],dis[N][N];
vector<int>vec[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dis[i][j]=0x3f3f3f3f;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%lld",&a[i][j],&t[i][j]);
			vec[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=1;i<=m;i++){
		if(vec[i].size()<2)continue;
		for(int u:vec[i]){
			for(int v:vec[i]){
				if(v==u)continue;
				int l=lower_bound(a[u]+1,a[u]+k[u]+1,i)-a[u];
				int r=lower_bound(a[v]+1,a[v]+k[v]+1,i)-a[v];
				dis[u][v]=min(dis[u][v],(ll)t[u][l]+t[v][r]);
				dis[v][u]=min(dis[v][u],(ll)t[u][l]+t[v][r]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int l=1;l<=n;l++){
			for(int r=1;r<=n;r++){
				if(l==r)continue;
				dis[l][r]=min(dis[l][i]+dis[i][r],dis[l][r]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll ans=LLONG_MAX;
		for(int u:vec[x[i]]){
			for(int v:vec[y[i]]){
				int l=lower_bound(a[u]+1,a[u]+k[u]+1,x[i])-a[u];
				int r=lower_bound(a[v]+1,a[v]+k[v]+1,y[i])-a[v];
				ans=min(ans,dis[u][v]+t[u][l]+t[v][r]+w[x[i]]+w[y[i]]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*


*/