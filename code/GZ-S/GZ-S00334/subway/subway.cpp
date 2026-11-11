//GZ-S00334 华东师范大学附属贵阳学校 向耕立
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_N=5*1e5+10,INF=1e17+10;
typedef struct pt{ll u,t;}pt;
ll c,n,m,d,q,w[MAX_N],x,y;
vector<pt> v[MAX_N];
ll find(ll x,ll y){
	queue<pt> q;
	q.push({x,0});
	ll pz=0,ans=INF,dis[MAX_N];
	pt now;
	bool vis[MAX_N];
	memset(vis,false,sizeof(vis));
	while(!q.empty()){
		now=q.front();
		q.pop();
		vis[now.u]=true;dis[now.u]=now.t;
		// cout<<now.u<<"->"<<now.t<<endl;
		bool flg=true;
		for(const auto &[a,t]:v[now.u]){
			// cout<<a<<':'<<t<<endl;
			// if(a==y){
			// 	ans=min(ans,now.t+t);
			// 	flg=false;
			// }
			// if(v[a].size()==2&&!vis[a]&&(v[v[a][0].u].size()==1||v[v[a][1].u].size()==1))vis[a]=true;
			// else if(!vis[a]&&flg)q.push({a,now.t+t});
			if(a==y){
				dis[a]=(dis[a]==0?now.t+t:min(dis[a],now.t+t));
			}else if(a<=m&&v[a].size()<2){vis[a]=true;}
			else if(!vis[a]&&flg){q.push({a,now.t+t});dis[a]=now.t+t;}
			else if(vis[a]){
				// if((dis[a]!=0&&dis[a]>now.t+t)||dis[a]==0){q.push({now.u,now.t});
				ll u=dis[y]-dis[a];
				dis[a]=(dis[a]==0?now.t+t:min(dis[a],now.t+t));
				if(u>0)dis[y]=min(dis[y],dis[a]+u);
			}
		}
	}	
	ans=dis[y];
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1,w;i<=m;i++){
		cin>>w;
		v[i].push_back({i+m,w});
		v[i+m].push_back({i,w});
	}
	for(ll i=1,k;i<=n;i++){
		cin>>k;
		for(ll j=1,a,t;j<=k;j++){
			cin>>a>>t;
			v[i+10*m].push_back({a,t});
			v[a].push_back({i+10*m,t});
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<find(x+m,y+m)<<endl;
	}
	return 0;
}