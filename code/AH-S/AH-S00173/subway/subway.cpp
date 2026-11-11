#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
ll w[500005];
ll ww[500005][21];
ll dis[505][505];
struct sj{
	int a;
	ll t;
};
vector<sj> e[500005];

ll read(){
	ll an=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		an=an*10+c-'0';
		c=getchar();
	}
	return an*f;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) w[i]=read();
	int k;
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			ll vvv=read(),www=read();
			ww[vvv][i]=www;
			e[vvv].push_back({i,www});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e16;
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int len=e[i].size();
		if(len==1) continue;
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				if(j==k) continue;
				int st=e[i][j].a,to=e[i][k].a;
				dis[st][to]=min(dis[st][to],e[i][j].t+e[i][k].t);
				dis[to][st]=dis[st][to];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(j==k || i==k) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	int xx,yy;
	while(q--){
		scanf("%d%d",&xx,&yy);
		ll ans=1e18;
		int len1=e[xx].size(),len2=e[yy].size();
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				int st=e[xx][i].a,to=e[yy][j].a;
				ans=min(ans,dis[st][to]+ww[xx][st]+ww[yy][to]);
			}
		}
		printf("%lld\n",ans+w[xx]+w[yy]);
	}
}
