#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5,MAXM=5e2+5;
int c,n,m,d,q;
int w[MAXN],dis[MAXM][MAXM];
vector<pair<int,int>>v[MAXN];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%lld %lld",&a,&t);
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto t1:v[i]){
			for(auto t2:v[i]){
				if(t1.first==t2.first)continue;
				if(t1.second==1e18||t2.second==1e18)continue; 
				dis[t1.first][t2.first]=min(dis[t1.first][t2.first],t1.second+t2.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||k==j)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%lld %lld",&x,&y);
		int ans=1e18;
		for(auto t1:v[x]){
			for(auto t2:v[y]){
				ans=min(ans,dis[t1.first][t2.first]+t1.second+t2.second);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
