#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+9;
int c,n,m,d,q,k[509];
ll w[maxn],dis[509][509];
vector<ll>a[509],t[509];
vector<pair<int,ll>>sp[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
//		cin>>w[i];
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
//		cin>>k[i];
		scanf("%lld",&k[i]);
		a[i].resize(k[i]+9);
		t[i].resize(k[i]+9);
		for(int j=1;j<=k[i];j++){
//			cin>>a[i][j]>>t[i][j];
			scanf("%d%d",&a[i][j],&t[i][j]);
			sp[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dis[i][j]=dis[j][i]=1e17;
		}
	}
	ll u,v,wu,wv,ans;
	for(int i=1;i<=m;i++){
		for(int j=0;j<sp[i].size();j++){
			for(int k=j+1;k<sp[i].size();k++){
				u=sp[i][j].first;v=sp[i][k].first;wu=sp[i][j].second;wv=sp[i][k].second;
				dis[u][v]=min(dis[u][v],wu+wv);
				dis[v][u]=dis[u][v];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
//		cin>>u>>v;
		scanf("%d%d",&u,&v);
		ans=1e17;
		for(int j=0;j<sp[u].size();j++){
			for(int k=0;k<sp[v].size();k++){
				ans=min(ans,sp[u][j].second+sp[v][k].second+dis[sp[u][j].first][sp[v][k].first]);
//				cout<<u<<" "<<v<<"   "<<sp[u][j].first<<" "<<sp[u][j].second<<"   "<<sp[v][k].first<<" "<<sp[v][k].second<<endl;
			}
		}
//		cout<<ans<<" "<<w[u]<<" "<<w[v]<<endl;
//		cout<<ans+w[u]+w[v]<<endl;
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
