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
const int N=1e6+50;
int OP,n,k,b[13],pv[13],ans,R,d[13];
vector<int> G[N];
inline void ss(int u){
	pv[u]=1;
	for(auto v:G[u]){
		if(b[v]&&!pv[v]){
			ss(v);
		}
	}
}
inline bool pd(){
	for(int i=1;i<=n;++i)pv[i]=0;
	int res=0;
	for(int i=1;i<=n;++i){
		if(b[i]&&!pv[i]){
			++res;if(res>2)return 0;
			ss(i);
		}
	}
	return 1;
}
inline void co(int u,int bs){
	
	for(auto v:G[u]){
		if(!b[v]&&bs+1<d[v]){
			d[v]=bs+1;
			co(v,bs+1);
		}
	}
}
inline int js(){
	for(int i=1;i<=n;++i)if(!b[i])d[i]=1e18;

	R=0;
	for(int i=1;i<=n;++i){
		if(b[i])co(i,0);
	}
	for(int i=1;i<=n;++i)if(!b[i])R=max(R,d[i]);
}
inline void dr(int u,int alr){
	if(u==n+1&&alr!=k)return;
	if(alr==k){
		if(pd())ans=min(ans,js());
		return;
	}
	b[u]=1;
	dr(u+1,alr+1);
	b[u]=0;
	dr(u+1,alr);
}
inline void solve(){
	ans=1e18;
	for(int i=1;i<=n;++i)G[i].clear(),b[i]=0;
	n=read();k=read();
	for(int i=1,u,v;i<n;++i){
		u=read();v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dr(1,0);
	printf("%lld\n",ans);
	return;
}
signed main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	OP=read();
	int ttt=read();
	while(ttt--)solve();
	
	return 0;
}
