#include<bits/stdc++.h>
#define ll long long
#define pa pair<ll,ll>
using namespace std;
int head[211005],nxt[211006],to[210006],y,k,a,t;
ll n,m,x,c,d,q,r,sum,ans,wi[210005],o;
ll val[211006],cnt;
map<int,bool>fl[500005];
map<int,ll>dis[500005];
void add(int u,int v,int w){
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	val[cnt]=w;
}
priority_queue<pa,vector<pa>,greater<pa>>qi;
void ks(){
	while(!qi.empty()){
		qi.pop();
	}
	dis[x][x]=0;
	qi.push({0,x});
	while(!qi.empty()){
		int u=qi.top().second;
		qi.pop();
		if(fl[x][u])continue;
		fl[x][u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];ll w=val[i];
			if(dis[x][v]>dis[x][u]+w){
				dis[x][v]=dis[x][u]+w;
				if(fl[x][v]==0)
					qi.push({dis[x][v],v});
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>wi[i];
	}
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			add(m+i,a,t);
			add(a,m+i,t);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ks();
		cout<<dis[x][y]+wi[x]+wi[y]<<"\n";
	}
	return 0;
}
