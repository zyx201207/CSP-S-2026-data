#include<bits/stdc++.h>
#define fi first
#define se second
#define getc (u==v&&(v=(u=In)+fread(In,1,32768,stdin)),*u++)
using namespace std;
using ll=long long;enum{N=500005};
int n,m,q,w[N];map<int,ll>ans[N];
ll d[505][505];vector<pair<int,int>>s[N];
char *u,*v,In[32768];void read(int &x){
	char c=getc;x=0;for(;!isdigit(c);c=getc);
	for(;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getc);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(n),read(n),read(m),read(q),read(q);for(int i=1;i<=m;read(w[i++]));
	memset(d,0x3f,sizeof d);for(int i=1,k;i<=n;d[i][i]=0,i++)
		{read(k);for(int x,y;k--;read(x),read(y),s[x].push_back({i,y}));}
	for(int i=1;i<=m;i++) for(auto p:s[i]) for(auto q:s[i])
		d[p.fi][q.fi]=min(d[p.fi][q.fi],1ll*p.se+q.se);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[j][k]);
	for(int u,v;q--;printf("%lld\n",ans[u][v]+w[u]+w[v])){
		read(u),read(v);if(u<v) swap(u,v);if(!ans[u][v]){
			ll res=1e18;for(auto p:s[u]) for(auto q:s[v])
				res=min(res,d[p.fi][q.fi]+p.se+q.se);ans[u][v]=res;}
	}cerr<<clock();
	return 0;
}