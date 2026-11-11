#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=1e6+10;
const long long inf=1e18;
int C,n,m,d,q,tot,a[N],dt[N],s[N],f[N],ff[N],lg;
int dfn[N],low[N],st[N],rd[N],tp,cnt,num;
int sy[N],jc[N];
int dep[N],fp[N][21];
long long dis[N],D[N],siz[N];
bool ins[N];
long long w[N],ans;
queue<int> qe;
vector<pair<int,int> > v[N],scc,vp[N<<1];
void tarjan(int x,int fa,int tj){
	dfn[x]=low[x]=++cnt;
	st[++tp]=x,rd[tp]=tj,ins[x]=1;
	f[x]=fa;
	int y,len,dd=0,z,ll;
	ll=v[x].size();
	for(int i=0;i<ll;i++){
		y=v[x][i].first;
		if(y==fa) continue;
		if(!dfn[y]) tarjan(y,x,v[x][i].second),low[x]=min(low[x],low[y]);
		else if(ins[x]) low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		num++;
		scc.clear();
		while(1){
			y=st[tp],z=rd[tp];
			tp--;
			scc.push_back(mp(y,z));
			sy[y]=num;
			if(x==y)break;
			ins[y]=0;
		}
		len=scc.size();
		if(len<2){
			sy[x]=0;
			num--;
			return;
		}
		for(int i=len-2;i>=0;i--) dis[scc[i].first]=dis[scc[i+1].first]+scc[i].second;
		for(int i=0;i<ll;i++){
			if(v[x][i].first==scc[0].first){dd=v[x][i].second;break;}
		}
		D[num]=dis[scc[0].first]+dd;
	}
}
void dfs(int x,int fa){
	int y;
	dep[x]=dep[fa]+1;
	fp[x][0]=fa;
	for(int i=1;i<=lg;i++) fp[x][i]=fp[fp[x][i-1]][i-1];
	int len=vp[x].size();
	for(int i=0;i<len;i++){
		y=vp[x][i].first;
		siz[y]=siz[x]+vp[x][i].second;
		dfs(y,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=lg;i>=0;i--){
		if(dep[x]-(1<<i)>=dep[y]) x=fp[x][i];
	}
	if(x==y) return x;
	for(int i=lg;i>=0;i--){
		if(fp[x][i]!=fp[y][i]) x=fp[x][i],y=fp[y][i];
	}
	return fp[x][0];
}
int count(int x,int fa){
	int dd=dep[x]-dep[fa]-1;
	for(int i=lg;i>=0;i--){
		if(dd-(1<<i)>=0) dd-=(1<<i),x=fp[x][i];
	}
	return x;
}
void spfa(int st){
	while(!qe.empty()) qe.pop();
	for(int i=1;i<=tot;i++) dis[i]=inf;
	dis[st]=0;
	qe.push(st);
	int x,y,z;
	while(!qe.empty()){
		x=qe.front(),qe.pop();
		for(int i=0;i<v[x].size();i++){
			y=v[x][i].first,z=v[x][i].second;
			if(dis[y]>dis[x]+z){dis[y]=dis[x]+z;qe.push(y);}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	int x,y,z,d1,d2,dd,k,xx,yy,len;
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	tot=m;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>s[j];
			dt[j]=++tot;
			v[a[j]].push_back(mp(dt[j],s[j]));
			v[dt[j]].push_back(mp(a[j],s[j]));
		}
		for(int j=1;j<k;j++) v[dt[j]].push_back(mp(dt[j+1],0)),v[dt[j+1]].push_back(mp(dt[j],0));
	}
	if(tot-m<=20000){
		while(q--){
			cin>>x>>y;
			spfa(x);
			cout<<dis[y]+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=tot;i++){
		if(!dfn[i]) tarjan(i,0,0);
	}
	for(int i=1;i<=tot;i++){
		x=i;
		len=v[i].size();
		for(int j=0;j<len;j++){
			y=v[i][j].first;
			if(f[x]==y) continue;
			if(sy[x]==0&&sy[y]==0) vp[x].push_back(mp(y,v[x][j].second));
			else if(sy[x]==0&&sy[y]) jc[sy[y]]=y,vp[x].push_back(mp(sy[y]+tot,v[x][j].second));
			else if(sy[x]&&sy[y]&&sy[x]==sy[y]) continue;
			else if(sy[x]&&sy[y]) jc[sy[y]]=y;
		}
	}
	for(int i=1;i<=tot;i++){
		x=i;
		len=v[i].size();
		for(int j=0;j<len;j++){
			y=v[i][j].first;
			if(f[x]==y) continue;
			if(sy[x]==sy[y]) continue;
			if(!sy[x]) continue;
			if(!sy[y]){
				dd=min(dis[x],D[sy[x]]-dis[x]);
				vp[sy[x]+tot].push_back(mp(y,dd+v[i][j].second));
			}else{
				d1=min(dis[x],D[sy[x]]-dis[x]);
				d2=min(dis[y],D[sy[y]]-dis[y]);
				vp[sy[x]+tot].push_back(mp(sy[y]+tot,d1+d2+v[i][j].second));
			}
		}
	}
	lg=log2(tot+num);
	dfs(1,0);
	while(q--){
		cin>>x>>y;
		if(sy[x]) xx=sy[x]+tot;
		else xx=x;
		if(sy[y]) yy=sy[y]+tot;
		else yy=y;
		if(sy[x]&&sy[y]&&sy[x]==sy[y]){
			ans=min(abs(dis[x]-dis[y]),D[sy[x]]-abs(dis[x]-dis[y]));
		}else{
			if(xx<yy) swap(xx,yy);
			z=lca(xx,yy);
			ans=siz[xx]+siz[yy]-2*siz[z];
			if(xx>tot) ans+=min(dis[x],D[xx-tot]-dis[x]);
			if(yy>tot) ans+=min(dis[y],D[yy-tot]-dis[y]);
			if(z>tot){
				d1=count(xx,z),d2=count(yy,z);
				d1=ff[d1],d2=ff[d2];
				ans+=min(abs(dis[d1]-dis[d2]),D[z-tot]-abs(dis[d1]-dis[d2]));
			}
		}
		ans=ans+w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}