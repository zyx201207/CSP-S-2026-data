#include<bits/stdc++.h>
using namespace std;
const int N=5e5+54,M=5e6;
using ll=long long;
int c,n,m,d,q;
ll w[N];
int nxt[M],head[N],to[M],cnt;
ll l[M]; 
void add(int x,int y,ll lx){
	nxt[++cnt]=head[x];
	l[cnt]=lx;
	to[cnt]=y;
	head[x]=cnt;
}
ll dis[505][505];
pair<int,ll>tmp[50],tmp2[50];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		ll lne=0;
		int v=0;
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&v,&lne);
			add(v,i,lne);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int top=0;
		for(int j=head[i];j;j=nxt[j])tmp[++top]={to[j],l[j]};
		for(int k=1;k<=top;k++){
			for(int kk=k+1;kk<=top;kk++){
				int k1=tmp[k].first,kk1=tmp[kk].first;
				dis[k1][kk1]=dis[kk1][k1]=tmp[k].second+tmp[kk].second;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(k==j)continue;
				if(i==j)continue;
				if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		ll ans=1e18;
		int top=0,top2=0;
		for(int j=head[u];j;j=nxt[j])tmp[++top]={to[j],l[j]};
		for(int j=head[v];j;j=nxt[j])tmp2[++top2]={to[j],l[j]};
		for(int i=1;i<=top;i++){
			for(int j=1;j<=top2;j++){
				ans=min(ans,w[u]+w[v]+tmp[i].second+tmp2[j].second+dis[tmp[i].first][tmp2[j].first]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
*/
