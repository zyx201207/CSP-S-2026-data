#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int MAX=5e5+10,NAX=5e2+10;
typedef long long ll;
typedef pair<int,ll> pii;
int c,n,m,d,q;
ll w[MAX],k,a,t;
int x,y;
vector<pii> sttol[MAX];
ll dist[NAX][NAX];
inline ll read(){
	ll ret=0;char ch;
	while(ch=getchar(),!isdigit(ch));
	ret=ch-'0';
	while(ch=getchar(),isdigit(ch)){
		ret=ret*10+(ch-'0');}
	return ret;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	c=read(),n=read(),m=read(),d=read(),q=read();
//	for(int i=1;i<=m;i++){scanf("%d",w+i);}
	for(int i=1;i<=m;i++){w[i]=read();}
	for(int i=1;i<=n;i++){
//		scanf("%d",&k);
		k=read();
		for(int j=1;j<=k;j++){
//			scanf("%d%d",&a,&t);
			a=read(),t=read();
			sttol[a].emplace_back(i,t);
		}
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++){
		auto &sl=sttol[i];
		for(int j=0;j<sl.size();j++){
			for(int k=j+1;k<sttol[i].size();k++){
				dist[sl[j].f][sl[k].f]=dist[sl[k].f][sl[j].f]=
				min(dist[sl[j].f][sl[k].f],sl[j].s+sl[k].s);
			}
		}
	}
	for(int i=1;i<=n;i++){dist[i][i]=0;}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
//		scanf("%d%d",&x,&y);
		x=read(),y=read();
		ll ans=1e18;
		for(int i=0;i<sttol[x].size();i++){
			auto r1=sttol[x][i];
			for(int j=0;j<sttol[y].size();j++){
				auto r2=sttol[y][j];
				ans=min(ans,dist[r1.f][r2.f]+r1.s+r2.s);
			}
		}
		printf("%lld\n",w[x]+w[y]+ans);
	}
	return 0;
}
/*

*/
