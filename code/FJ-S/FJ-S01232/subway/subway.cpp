#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e4+5;
ll c,n,m,d,q,x,y,k[N],w[M],dis[M],vis[M],a[N][M],t[N][M],id[N][M];
vector<ll> g[M];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
ll read(){
	char ch;ll s=0,w=1;
	while((ch=getchar())>'9' || ch<'0') if(ch=='-') w=-1;
	while(ch>='0' && ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i][j]=read(),t[i][j]=read();
			id[i][a[i][j]]=j;
			g[a[i][j]].push_back(i);
		}
	}
	while(q--){
		x=read(),y=read();
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		pq.push({0,x});
		dis[x]=0;
		while(!pq.empty()){
			ll u=pq.top().second;
			pq.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto v:g[u]){
				for(int i=1;i<=k[v];i++){
					if(a[v][i]==u) continue; 
					if(dis[u]+t[v][id[v][u]]+t[v][i]<dis[a[v][i]]){
						dis[a[v][i]]=dis[u]+t[v][id[v][u]]+t[v][i];
						pq.push({dis[a[v][i]],a[v][i]}); 
					}
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
