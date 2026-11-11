#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,M=5e5+10;
typedef long long ll;
ll G[N][N],a[M];
int c,n,m,d,q;
vector<pair<int,ll> >t[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//cout<<1; 
	memset(G,0x3f,sizeof G);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}

	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		//cout<<k;
		for(int j=1;j<=k;j++){
			int ai;
			ll t1;
			scanf("%d%lld",&ai,&t1);
			t[ai].push_back({i,t1});
		}
	}
	//cout<<q;
	for(int i=1;i<=n;i++) G[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<t[i].size();j++){
			for(int j1=j+1;j1<t[i].size();j1++){
				int u=t[i][j].first,v=t[i][j1].first;
				ll t1=t[i][j].second,t2=t[i][j1].second;
				G[u][v]=G[v][u]=min(G[u][v],t1+t2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(G[i][k]<=1e18+10&&G[k][j]<=1e18+10){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);}
			}
		}
	}
	while(q--){
		int st,ed;
		scanf("%d%d",&st,&ed);
		ll ans=1e18+10;
		for(int j=0;j<t[st].size();j++){
			for(int j1=0;j1<t[ed].size();j1++){
			int u=t[st][j].first,v=t[ed][j1].first;
			ll t1=t[st][j].second,t2=t[ed][j1].second;
		//	cout<<G[u][v]<<" "<<t1<<" "<<t2<<"\n";
			ans=min(ans,G[u][v]+t1+t2);
			}
	}
	   ans+=a[st]+a[ed];
	   cout<<ans<<"\n";
	}
	return 0;
}
