#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
const long long M=500005;
long long c,n,m,d,p,ll,w,k,a,t,l,r,h[N],idx,dis[N];
bool vis[N];
struct Edge{
	long long from,to,w,next;
}e[N];
void init(){
	for(long long i=1;i<=23*n;i++) h[i]=-1;
}
void add(long long from,long long to,long long w){
	e[idx].from=from;
	e[idx].to=to;
	e[idx].w=w;
	e[idx].next=h[from];
	h[from]=idx++;
}
struct node{
	long long d,t;
};
bool operator<(node a,node b){
	return a.d>b.d;
}
priority_queue<node> pq;
void Dij(long long st){
	for(long long i=1;i<=23*n;i++) dis[i]=1e18,vis[i]=false;
	dis[st]=0;
	pq.push({0,st});
	while(!pq.empty()){
		node p=pq.top();
		pq.pop();
		if(vis[p.t]) continue;
		else vis[p.t]=true;
		for(long long i=h[p.t];i!=-1;i=e[i].next){
			long long u=e[i].to;
			if(dis[u]>dis[p.t]+e[i].w){
				dis[u]=dis[p.t]+e[i].w;
				pq.push({dis[u],u});
			}
		}
	}
}
map<long long,bool> mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>m>>n>>d>>p;
	init();
	long long cnt=3*n+1;
	for(long long i=1;i<=n;i++){
		cin>>w;
		add(i+n,i+2*n,w);
		add(i+2*n,i+n,w);
	}for(long long i=1;i<=m;i++){
		cin>>k;
		long long la=0;
		for(long long j=1;j<=k;j++){
			cin>>a>>t;
			if(!mp[a]){
				add(a,a+n,t);
				add(a+n,a,t);
				mp[a]=true;
				if(la!=0){
					add(la,a,0);
					add(a,la,0);
				}la=a;
			}else{
				add(a+n,cnt,t);
				add(cnt,a+n,t);
				if(la!=0){
					add(la,cnt,0);
					add(cnt,la,0);
				}la=cnt;
				cnt++;
			}
		}
	}
	while(p--){
		cin>>l>>r;
		if(ll!=0){
			if(ll==l){
				cout<<dis[r+2*n]<<endl;
			}else{
				Dij(l+2*n);
				cout<<dis[r+2*n]<<endl;
				ll=l;
			}
		}else{
			Dij(l+2*n);
			cout<<dis[r+2*n]<<endl;
			ll=l;
		}
	}
	return 0;
}
