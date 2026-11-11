#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>57||c<48){if(c==45)f=-1;c=getchar();}
	while(c<=57&&c>=48){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
typedef pair<int,int> PII;
const int N=5e5+50;
int OP,n,m,D,Q,WW[N],kk[550],d[550][550],vs[N*2],qt[550];
vector<PII> A[N*2];
//int hd[N*4],tot;
//struct Ed{
//	int to,ne,w;
//}e[N*4];
//inline int add(int u,int v,int w){
//	e[++tot]={v,hd[u],w};
//	hd[u]=tot;
//}
vector<PII> G[N*2];
priority_queue <PII,vector<PII>,greater<PII> > q;
inline void dij(int S){
	while(q.size())q.pop();
	
	d[S][S]=0;
	q.push({0,S+m});
	
	while(q.size()){
		PII Top=q.top();q.pop();
		int dis=Top.first,u=Top.second;
		
		if(vs[u-m])continue;
		vs[u-m]=1;
		
		for(auto i:G[u]){
			if(i.first<=m)continue;
			int v=i.first-m,w=i.second;//cout<<v<<endl;
			
				if(dis+w<d[S][v]){
					d[S][v]=dis+w;
					q.push({dis+w,v+m});
				}
			
		}
	}
	return;
}
inline void solve(){
	n=read();m=read();D=read();Q=read();
	for(int i=1;i<=m;++i)WW[i]=read();
	for(int i=1;i<=n;++i){
		kk[i]=read();
		for(int j=1,V,W;j<=kk[i];++j){
			V=read();W=read();
			for(auto Top:A[V]){
				int x=Top.first,ww=Top.second;
				
				G[x+m].push_back({i+m,W+ww});
				G[i+m].push_back({x+m,W+ww});
//				add(x+m,i+m,W+ww);
//				add(i+m,x+m,W+ww);
			}
			A[V].push_back({i,W});
			G[V].push_back({i+m,W});
				G[i+m].push_back({V,W});
//			add(V,m+i,W);
//			add(m+i,V,W);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)d[i][j]=1e18,vs[j]=0;
	//	for(int j=1;j<=n;++j)qt[j]=1e18,vs[j]=0;
	
		dij(i);
	}
	for(int o=1,u,v;o<=Q;++o){
		u=read();v=read();
		int ans=1e18;
		for(auto i:G[u]){
			int U=i.first,uW=i.second;
			for(auto j:G[v]){
				int V=j.first,vW=j.second;
				ans=min(ans,uW+d[U-m][V-m]+vW);
			}
		}
		ans+=WW[u]+WW[v];
		printf("%lld\n",ans);
	}
//	cout<<d[1][2]<<endl;
	return;
}
signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	OP=read();
	int ttt=1;
	while(ttt--)solve();
	
	return 0;
}
