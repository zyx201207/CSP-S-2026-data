#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],tot,p[5000005],bian,st[1000005],ed[1000005];
bool ex[500005];
long long f[505][505];
int dis[505][505];
//void link(int u,int v,int w){
//	nxt[++tot]=h[u],V[tot]=v,W[tot]=w,h[u]=tot;nxt[++tot]=h[v],V[tot]=u,W[tot]=w,h[v]=tot;
//}
struct get{
	int pos,x,y;
}a[500005];
vector<pair<int,int> >be[500005];
void fly(){
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		for(int j=1,x,y;j<=k;++j){
		cin>>x>>y;a[++bian].pos=i,a[bian].x=x,a[bian].y=y;
	}
	}
	for(int i=1;i<=q;++i){
		cin>>st[i]>>ed[i];
//		if(!p[st[i]])p[st[i]]=++cnt;
//		if(!p[ed[i]])p[ed[i]]=++cnt;
	}
	for(int i=1;i<=bian;++i){
//		if(p[a[i].x]){
			be[a[i].x].emplace_back(make_pair(a[i].pos,a[i].y));
//		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i^j)f[i][j]=2e18;
	int s=1;
	for(int i=1;i<=m;++i){
		for(int j=0;j<be[i].size();++j){
			for(int k=0;k<be[i].size();++k){
			 pair<int,int> d=be[i][j],e=be[i][k];
			if(d.first^e.first)f[d.first][e.first]=min(f[d.first][e.first],1ll*d.second+e.second);
		}
		}
	}
//	if(s)return 0;
//	for(int i=1;i<=n;++i){
//	for(int j=1;j<=n;++j)cout<<f[i][j]<<" ";cout<<endl;}
	fly();
	for(int i=1;i<=q;++i){
		long long res=2e18;pair<int,int>d,e;
		for(int j=0;j<be[st[i]].size();++j){
			for(int k=0;k<be[ed[i]].size();++k){
				d=be[st[i]][j],e=be[ed[i]][k];
			res=min(res,f[d.first][e.first]+d.second+e.second);
			}
		}
		cout<<(res+w[st[i]]+w[ed[i]])<<'\n';
	}
	return 0;
}

