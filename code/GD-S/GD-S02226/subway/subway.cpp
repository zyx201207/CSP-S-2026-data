#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const ll MAXM=2e4+5;
const ll MAXN=505;
const ll INF=1e18;
ll c,n,m,d,Q,w[MAXM],k[MAXN],a[MAXN][MAXM],t[MAXN][MAXM];
vector<ll> jg[MAXM];
ll dis[MAXM][MAXN];
vector<ll> line[MAXN];
ll t2[MAXM][MAXN],t3[MAXN][MAXM];
map<pair<ll,pair<ll,ll> >,ll> vis;
map<pair<ll,ll>,ll> zai;
priority_queue<pair<ll,pair<ll,ll> >,vector<pair<ll,pair<ll,ll> > >,greater<pair<ll,pair<ll,ll> > > > q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
			t2[a[i][j]][i]=t[i][j];
			t3[i][a[i][j]]=t[i][j];
			zai[{a[i][j],i}]=1;
			line[i].push_back(a[i][j]);
			//mp[{i,a[i][j]}]=j;//mp[i,j]代表第i条线路上的x节点是第几个站点 
			jg[a[i][j]].push_back(i);
		}
	}
	while(Q--){
		ll x,y;
		cin>>x>>y;
		ll ans1=INF;
		bool same=false;
		for(int i=1;i<=n;++i){
			if(zai[{x,i}]&&zai[{y,i}]){
				same=true;
				ans1=w[x]+w[y]+t2[x][i]+t3[i][y];
			}
		}
		if(ans1!=INF){
			cout<<ans1<<'\n';
			continue;
		}
		for(int i=1;i<=m;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=INF;
			}
			
		}
		for(ll sb:jg[x]){
			dis[x][sb]=t2[x][sb];
		}
		//q[u,v,w]代表当前mindis是w,到了点u，在v号线 
		for(ll sb:jg[x]){
			q.push({t2[x][sb],{x,sb}});
			//vis[{0,{x,sb}}]=1;
		}
		while(!q.empty()){
			auto cur=q.top();
			q.pop();
			ll ww=cur.fi,uu=cur.se.fi,vv=cur.se.se;
			vis[{ww,{uu,vv}}]=1;
			for(ll sb:jg[uu]){
			//	cout<<"node"<<uu<<":"<<" "<<sb<<'\n';
				//cout<<jg[uu].size();
				
				ll nxdis=ww+t2[uu][vv]+t3[sb][uu];
			//	cout<<nxdis<<'\n';
				if(vis[{nxdis,{uu,sb}}]){
					continue;
				} 
				if(dis[uu][sb]>nxdis){
					//cout<<vv<<" "<<sb<<" "<<uu<<'\n';
					dis[uu][sb]=nxdis;
					q.push({nxdis,{uu,sb}});
				}
			} 
			for(ll sb:line[vv]){
			//	cout<<"line"<<vv<<":"<<sb<<'\n';
				if(vis[{ww,{sb,vv}}]){
					continue;
				}
				if(dis[sb][vv]>ww){
					dis[sb][vv]=ww;
				//	cout<<uu<<" "<<sb<<" "<<ww<<'\n';
				}
				q.push({ww,{sb,vv}});
			}
		}
		ll ans=INF;
		for(int i=1;i<=n;++i){
			ans=min(ans,dis[y][i]+w[y]+w[x]+t3[i][y]);
		}
		if(same&&ans1<ans){
			cout<<ans1<<'\n';
			continue;
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
