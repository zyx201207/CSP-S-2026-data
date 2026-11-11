/*先用floyed把线与线之间算明白*/
#include<bits/stdc++.h>
using namespace std;
const int N=501,M=5e5+1;
typedef long long ll;
inline ll read(){
	ll x=0,k=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')k=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return k*x;
}
ll c,n,m,d,q;//n是地铁线路数，m是地铁站数 
ll dis[N][N],INF,t[M];//地铁站到站厅 
struct Node{int to;ll w;};
vector<Node> ls[N],sl[M];//ls:line（to）state
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	INF=dis[0][0];
	c=read(),n=read(),m=read(),d=read(),q=read(); 
	for(int i=1;i<=m;++i)t[i]=read();
	for(int i=1;i<=n;++i){//线路 
		int k=read();
		for(int _=1;_<=k;++_){
			int j=read();ll w=read();//站厅，时间 
			ls[i].push_back({j,w});
			sl[j].push_back({i,w});
		}
	}
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int lu=1;lu<=n;++lu){
		for(Node s:ls[lu]){
			for(Node lv:sl[s.to]){
				dis[lu][lv.to]=dis[lv.to][lu]=min(1LL*s.w+lv.w,dis[lu][lv.to]);
			}
		}
	}	
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int _=1;_<=q;++_){
		int u=read(),v=read();
		ll base=t[u]+t[v],ans=INF;
		for(Node l1:sl[u]){
			for(Node l2:sl[v]){
				ans=min(ans,base+l1.w+l2.w+dis[l1.to][l2.to]);
			}
		}
		printf("%lld\n",ans);
	}
}
