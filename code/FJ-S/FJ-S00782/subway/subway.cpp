#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll> ;
#define pb push_back
#define fi first
#define se second
inline ll read(){
	ll f=1,x=0; char ch;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-48;ch=getchar();}
	return f*x;
}
const ll INF=4e18;
const ll N=505;
const ll D=20;
const ll M=5e5+5;
const ll Q=1e5+5;
ll _,n,m,d,Ques;
ll w[M];
vector <pii> g[M];
ll cnt[M];
void add(ll u,ll v,ll w){
	g[u].pb({w,v});
	return ;
}
struct Node{
	ll l,r,bh,ans;
}query[Q];
ll dis[M*D];
bool vis[M*D];
priority_queue <pii,vector<pii>,greater<pii> > q;
void dij(ll s){
	fill(dis+1,dis+m+1+m*d,INF);
	memset(vis,0,sizeof(vis));
	while(q.size()) q.pop();
	dis[s]=0;
	q.push({0,s});
	while(q.size()){
		ll dlt=q.top().se;
		q.pop();
		if(vis[dlt]) continue;
		vis[dlt]=1; 
		for(pii p : g[dlt]){
			if(dis[p.se]>dis[dlt]+p.fi){
				dis[p.se]=dis[dlt]+p.fi;
				q.push({dis[p.se],p.se}); 
			}
		}
	}
	return ;
}
bool cmp_l(Node x,Node y){
	return x.l<y.l;
}
bool cmp_id(Node x,Node y){
	return x.bh<y.bh;
}
int main(){
	 freopen("subway.in","r",stdin);
	 freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	_=read();
	n=read(),m=read(),d=read(),Ques=read();
	for(ll i=1;i<=m;i++) w[i]=read();
	for(ll i=1,k,zhiq,ztim;i<=n;i++){
		k=read();
		zhiq=read(); ztim=read(); ++cnt[zhiq];
		add(zhiq,m+(zhiq-1)*d+cnt[zhiq],ztim);
		add(m+(zhiq-1)*d+cnt[zhiq],zhiq,ztim);
		zhiq=m+(zhiq-1)*d+cnt[zhiq];
		for(ll j=2,num,tim;j<=k;j++){
			num=read(),tim=read(); ++cnt[num];
			add(num,m+(num-1)*d+cnt[num],tim);
			add(m+(num-1)*d+cnt[num],num,tim);
			num=m+(num-1)*d+cnt[num];
			add(zhiq,num,0); 
			add(num,zhiq,0);
		}
	}
	for(ll i=1;i<=Ques;i++){
		query[i].l=read(),query[i].r=read(),query[i].bh=i;
		if(query[i].l>query[i].r) swap(query[i].l,query[i].r); 
	}
	sort(query+1,query+1+Ques,cmp_l);
	query[0]={-1,-1};
	for(ll i=1;i<=Ques;i++){
		if(query[i].l!=query[i-1].l)
			dij(query[i].l);
		query[i].ans=dis[query[i].r]+w[query[i].l]+w[query[i].r];
	}
	sort(query+1,query+1+Ques,cmp_id);
	for(ll i=1;i<=Ques;i++){
		cout<<query[i].ans<<'\n';
	}
	return 0;
}
/*
input:
0 2 5 20 2
4 1 9 2 5 
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

AC_output:
32
17
*/
