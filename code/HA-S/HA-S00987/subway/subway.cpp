#include<bits/stdc++.h>
#define LL long long
using namespace std;
vector<LL> site[500010],ddis[500010];
LL c,n,m,d,q,cnt,now,nowdis,st,fi,dis[510][510],w[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&cnt);
		for(int j=1;j<=cnt;j++){
			scanf("%lld%lld",&now,&nowdis);
			site[now].push_back(i);
			ddis[now].push_back(nowdis);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=LONG_LONG_MAX;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		if(site[i].size()>=2){
			for(int j=0;j<site[i].size();j++){
				for(int k=j+1;k<site[i].size();k++){
					dis[site[i][k]][site[i][j]]=dis[site[i][j]][site[i][k]]=min(dis[site[i][j]][site[i][k]],ddis[i][j]+ddis[i][k]);
					
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(j==i||j==k) continue;
				if(dis[i][k]==LONG_LONG_MAX||dis[k][j]==LONG_LONG_MAX) continue;
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		LL ans=LONG_LONG_MAX;
		scanf("%lld%lld",&st,&fi);
		for(int j=0;j<site[st].size();j++){
			for(int k=0;k<site[fi].size();k++){
				ans=min(ans,dis[site[st][j]][site[fi][k]]+ddis[st][j]+ddis[fi][k]);
			}
		}
		ans=ans+w[st]+w[fi];
		printf("%lld\n",ans);
	}
	return 0;
}

