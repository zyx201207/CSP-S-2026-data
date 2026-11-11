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
const int N=2e6+50;
int OP,n,D,a[N],d[N],g[N],vs[N];
vector<int> G[N];
priority_queue <PII,vector<PII>,greater<PII> > q;

inline void pd(int s){
	while(q.size())q.pop();
	
	q.push({0,s});
	d[s]=0;g[s]=1;
	while(q.size()){
		PII Top=q.top();q.pop();
		int u=Top.second,dis=Top.first;
		if(vs[u])continue;
		vs[u]=1;
		
		for(auto v:G[u]){
			if(d[v]>dis+1){
				d[v]=dis+1;g[v]=1;
				q.push({d[v],v});
			}else if(d[v]==dis+1){
				++g[v];
			}
		}
	}
	
	return;
}
inline void svA(){
	int cc=a[2]-a[1];
	int ggg=D/cc;
	int stt=1+ggg+ggg-1;
	if(ggg<=1||stt>=n+1)stt=n+1;
	printf("%lld\n",n-stt+1);
	return;
}
inline void solve(){
	n=read();D=read();
	for(int i=1;i<=n;++i)a[i]=read(),G[i].clear();
	
	if(OP==11||OP==12){
		svA();return;
	}
	
	
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(a[j]-a[i]<=D){
				G[i].push_back(j);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			d[j]=1e18;g[j]=vs[j]=0;
		}
		pd(i);
		for(int j=1;j<=n;++j)if(g[j]==2)++ans;
	}
	printf("%lld\n",ans);
	return;
}
signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	OP=read();
	int ttt=read();
	while(ttt--)solve();
	
	return 0;
}
