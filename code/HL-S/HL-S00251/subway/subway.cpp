#include<bits/stdc++.h>
#define up(i,j,k) for(int i=j;i<=k;i++)
#define da(i,j,k) for(int i=j;i<=k;i++)
#define ll long long
#define db double
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#define int long long
using namespace std;
const int N=5e5+5,M=1e5+5;
int c,n,m,d,q;
int w[N];
vector<int> e[N];
int t[N][505]; //stage i->route j
int route[N]; //-1=trans 0=unknown >0=single
struct node2{
	int r,vv;
};
vector<node2> rr[N];
struct node{
	int x,y,id;
	ll ans;
}plan[M];
int from[N];
bool cmp(node xx,node yy){
	return xx.x<yy.x;
}
bool cmp1(node xx,node yy){
	return xx.id<yy.id;
}
ll rroute[N];
bool vis[N];
ll dis[N];
void dij(int u){
//	cout<<"!"<<u<<endl;
	up(i,1,m) vis[i]=0,dis[i]=1e18;
	vis[u]=1,dis[u]=w[u];
	priority_queue<pair<int,pair<int,pair<int,int> > > > q; //w v u
	for(int v:e[u]){
//		dis[v]=w[u]+t[u][route[v]];
		q.push(mp(w[u]+t[u][route[u]],mp(v,mp(u,u))));
	}
//	cout<<"@"<<dis[2]<<endl;
//	cout<<"[]"<<t[1][1]<<endl;
	while(!q.empty()){
		ll a=q.top().fi,b=q.top().se.fi,to=q.top().se.se.fi,last=q.top().se.se.se;
//		cout<<a<<" "<<b<<" "<<to<<" "<<last<<" "<<vis[b]<<endl;
		q.pop();
//		cout<<"@"<<dis[b]<<endl;
//		cout<<"@"<<dis[2]<<endl;
		from[b]=last;
		if(vis[b]) continue;
		if(route[to]>0) rroute[to]=route[to];
		if(route[last]>0) rroute[last]=route[last];
		if(route[b]>0) rroute[b]=route[b];
		else rroute[b]=rroute[to];
		dis[b]=min(dis[b],a);
		vis[b]=1;
//		vis[b]=1;
//		cout<<"@"<<dis[b]<<endl;
		if(route[b]==-1){
			for(int v:e[b]){
//				cout<<"!"<<v<<" "<<route[v]<<" "<<route[to]<<" "<<vis[v]<<endl;
				if(vis[v]) continue;
//				rroute[v]=rroute[b];
				if(route[v]==route[to]){
					q.push(mp(dis[last],mp(v,mp(to,b))));
//					cout<<":"<<dis[to]<<" "<<v<<" "<<to<<endl;
				}else q.push(mp(dis[b]+t[b][route[to]]+t[b][route[v]],mp(v,mp(b,b))));
//				dis[v]=min(dis[b]+t[b][route[b]]+t[b][route[v]],dis[v]);
//				vis[v]=1;
			}
		}else{
			for(int v:e[b]){
				if(vis[v]) continue;
//				dis[v]=min(a,dis[v]);
				q.push(mp(dis[b],mp(v,mp(b,b))));
//				vis[v]=1;
			}
		}
		
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	up(i,1,m) cin>>w[i];
	up(i,1,n){
		int k;
		cin>>k;
		int pre=0;
		up(j,1,k){
			int kk,tt;
			cin>>kk>>tt;
			if(j==1) pre=kk;
			else{
				e[pre].pb(kk);
				e[kk].pb(pre);
				rr[kk].push_back({i,pre});
//				toroute[kk]=i;
				pre=kk;
			}
			t[kk][i]=tt;
			if(route[kk]>0&&route[kk]!=i) route[kk]=-1;
			else if(route[kk]==0) route[kk]=i;
		}
	}
	up(i,1,q){
		cin>>plan[i].x>>plan[i].y;
		plan[i].id=i;
	}
	sort(plan+1,plan+q+1,cmp);
	up(i,1,q){
		int rrr;
		if(i==1){
			dij(plan[i].x);
//			int z=fa[plan[i].y];
//			if(route[z]==-1) z=plan[i].y;
			
			for(node2 zz:rr[plan[i].y]){
				if(zz.vv==from[plan[i].y]){
					rrr=zz.r;
					break;
				}
			}
			plan[i].ans=dis[plan[i].y]+t[plan[i].y][rrr]+w[plan[i].y];
		}else{
			if(plan[i].x==plan[i-1].x){
							for(node2 zz:rr[plan[i].y]){
				if(zz.vv==from[plan[i].y]){
					rrr=zz.r;
					break;
				}
			}
				plan[i].ans=dis[plan[i].y]+t[plan[i].y][rrr]+w[plan[i].y];
			}else{
				dij(plan[i].x);
							for(node2 zz:rr[plan[i].y]){
				if(zz.vv==from[plan[i].y]){
					rrr=zz.r;
					break;
				}
			}
				plan[i].ans=dis[plan[i].y]+t[plan[i].y][rrr]+w[plan[i].y];
			}	
		}
//		cout<<plan[i].y<<" "<<rroute[plan[i].y]<<endl;
	}
//	up(i,1,m) cout<<"?"<<dis[i]<<endl;
	sort(plan+1,plan+q+1,cmp1);
	up(i,1,q) cout<<plan[i].ans<<endl;
	return 0;
}
/*

*/

