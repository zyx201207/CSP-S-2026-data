#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,M=510;
struct sub{
	ll x,y;
}now;
vector<sub> a[N],s[M];
ll c,n,q,m,h,l,r,k[N],w[N];
ll sz,szl,szr,ans,d[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll u,v;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&h,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&now.x,&now.y);
			s[i].push_back(now);
			a[now.x].push_back(sub{i,now.y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) d[i][j]=2e18;
		}
	}
	for(int o=1;o<=m;o++){
		sz=a[o].size();
		for(int i=0;i<sz;i++){
			u=a[o][i].x;
			for(int j=i+1;j<sz;j++){
				v=a[o][j].x;
				d[u][v]=d[v][u]=min(d[u][v],a[o][i].y+a[o][j].y);
			}
		}
	}
	for(int o=1;o<=n;o++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][o]+d[o][j]);
			}
		}
	}
	while(q--){
		scanf("%lld%lld",&l,&r);
		ans=2e18;
		szl=a[l].size();
		szr=a[r].size();
		for(int i=0;i<szl;i++){
			u=a[l][i].x;
			for(int j=0;j<szr;j++){
				v=a[r][j].x;
				ans=min(ans,d[u][v]+a[l][i].y+a[r][j].y);
			}
		}
		printf("%lld\n",ans+w[l]+w[r]);
	}
	return 0;
} 
