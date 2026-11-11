#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <map>
#define ll long long
using namespace std;

struct edge{
	int v;
	int color;
};

const int maxn = 500+10,maxn2=5e5+10;
ll c,n,m,d,q;
int w[maxn2];
vector<edge> vc[maxn2];
int t[maxn][maxn2];
ll dis[maxn2];
bool vis[maxn2];

ll dij(int st,int en){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof vis);
	// w id color
	priority_queue<pair<ll,pair<int,int > > ,vector<pair<ll,pair<int,int> > > , greater<pair<ll, pair<int,int> > > >q;
	q.push(make_pair(0,make_pair(st,-1)));
	dis[st]=0;
	ll ans=0x3f3f3f3f;
	while(!q.empty()){
		int u=q.top().second.first,uc=q.top().second.second;
		if(u==en) ans=min(ans,dis[u]+=t[u][uc]);
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		bool s=(uc==-1?1:0);
		for(int i=0;i<vc[u].size();i++){
			int v=vc[u][i].v,vc1=vc[u][i].color;
			if(s) uc=vc1,dis[u]=t[u][vc1];
			if(vc1==uc){
				if(dis[u]<dis[v]){
					dis[v]=dis[u];
					q.push(make_pair(dis[v],make_pair(v,uc)));
				}
			}
			else {
				if(dis[u]+t[u][uc]+t[u][vc1]<dis[v]){
					dis[v]=dis[u]+t[u][uc]+t[u][vc1];
					q.push(make_pair(dis[v],make_pair(v,vc1)));
				}
			}
		}
	} 
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int pre=-1;
		for(int j=0;j<k;j++){
			int a,tmp;
			cin>>a;
			cin>>t[a][i];
			if(pre!=-1){
				vc[pre].push_back(edge{a,i});
				vc[a].push_back(edge{pre,i});
			}
			pre=a;
		}
	}
	for(int i=0;i<q;i++){
		int st,en;
		cin>>st>>en;
		cout<<dij(st,en)+w[st]+w[en]<<endl;
	}
	return 0;
}

