#include<bits/stdc++.h>
#define ll long long
using namespace std;
int tid,n,m,d,q,wf[500005],len[500005];
ll dis[505][505];
struct station{
	int lid,w;
}v[500005][22];
void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(tid),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++){
		read(wf[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		read(k);
		for(int j=1;j<=k;j++){
			int x,w;
			read(x),read(w);
			v[x][++len[x]]={i,w};
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int x=1;x<=len[i];x++){
			int xx=v[i][x].lid;
			ll w1=v[i][x].w;
			for(int y=x+1;y<=len[i];y++){
				int yy=v[i][y].lid;
				ll w2=v[i][y].w;
				dis[xx][yy]=dis[yy][xx]=min(dis[xx][yy],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		read(x),read(y);
		ll ans=1e18;
		for(int i=1;i<=len[x];i++){
			auto xx=v[x][i];
			for(int j=1;j<=len[y];j++){
				auto yy=v[y][j];
				ans=min(ans,dis[xx.lid][yy.lid]+xx.w+yy.w);
			}
		}
		ans+=wf[x]+wf[y];
		printf("%lld\n",ans);
	}
	return 0;
}
