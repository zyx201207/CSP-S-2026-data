#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10,M=2e5+10,Q=1e5+10;
int head[N],ver[M],nxt[M],tot=0;
ll wei[M];
ll dis[N];
ll ww[N];
bool vis[N];
ll read(){
	ll x=0,y=1;char ch;
	while((ch=getchar())<'0' || ch>'9') if(ch=='-') y=-1;
	while('0'<=ch && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*y;
}
void add(int u,int v,ll w){
	nxt[++tot]=head[u];
	ver[tot]=v;
	wei[tot]=w;
	head[u]=tot;
}
struct node{
	int u;
	ll w;
};
priority_queue<node,vector<node>,greater<node> > qu;
bool operator>(node x,node y){
	return x.w>y.w;
}
void Dij(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	qu.push({s,0}),dis[s]=0,vis[s]=0;
	while(!qu.empty()){
		int u=qu.top().u;qu.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=ver[i];
			ll w=wei[i];
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				qu.push({v,dis[v]});
			}
		}
	}
}
struct query{
	int l,r,id;
	ll ans;
}s[Q];
bool cmp(query x,query y){
	return x.l<y.l;
}
bool cmp2(query x,query y){
	return x.id<y.id;
}
void solve(int nn){
	for(int i=1;i<=nn;i++){
		int k=read();
		int u,v,t1,t2;
		if(k==0) continue;
		if(k==1){
			u=read(),t1=read();
			continue;
		}
		u=read();
		t1=read();
		v=read();
		t2=read();
		add(u,v,t1+t2);
		add(v,u,t1+t2);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,nn,mm,d,q;
	cin>>c>>nn>>mm>>d>>q;
	for(int i=1;i<=mm;i++){
		ww[i]=read();
	}
	if(7<=c && c<=11) solve(nn);
	else{
		for(int i=1;i<=nn;i++){
			int k=read();
			for(int j=1;j<=k;j++){
				int v=read();
				ll t=read();
				add(mm+i,v,t);
				add(v,mm+i,t);
			}
		}
	}
	for(int i=1;i<=q;i++){
		s[i].l=read();
		s[i].r=read();
		s[i].id=i;
	}
	sort(s+1,s+1+q,cmp);
	int p=1;
	for(int i=1;i<=mm;i++){
		if(s[p].l!=i) continue;
		Dij(i);
		while(s[p].l==i && p<=q){
			s[p].ans=dis[s[p].r];
			p++;
		}
	}
	sort(s+1,s+1+q,cmp2);
	for(int i=1;i<=q;i++){
		printf("%lld\n",s[i].ans+ww[s[i].l]+ww[s[i].r]);
	}
}
