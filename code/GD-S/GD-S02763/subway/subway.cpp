#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
using namespace std;
const int N=505,M=5e5+5;
int n,m,w[M];
ll dist[N][N];
vector<pii> s[M],g[N];
void dijkstar(int s){
	for(int i=1;i<=n;i++) dist[s][i]=1e18;
	priority_queue<pii,vector<pii>,greater<pii>> res;
	res.emplace(0,s);
	dist[s][s]=0;
	while(res.size()){
		int u=res.top().second;
		ll d=res.top().first;
		res.pop();
		if(d>dist[s][u]) continue;
		for(auto q:g[u]){
			int v=q.first,di=q.second;
			if(d+di<dist[s][v]) dist[s][v]=d+di,res.emplace(dist[s][v],v);
		}
	}
}
int main(){
	int c,d,q;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1,x,y,k;i<=n;i++){
		scanf("%d",&k);
	    for(int j=1;j<=k;j++){
	    	scanf("%d%d",&x,&y);
	    	s[x].emplace_back(i,y);
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=0;i<s[k].size();i++){
			for(int j=i+1;j<s[k].size();j++)
		       g[s[k][i].first].emplace_back(s[k][j].first,s[k][i].second+s[k][j].second),
			   g[s[k][j].first].emplace_back(s[k][i].first,s[k][i].second+s[k][j].second); 
		}
	}
    for(int i=1;i<=n;i++) dijkstar(i);
    int x,y;
    while(q--){
    	scanf("%d%d",&x,&y);
    	ll ans=1e17;
    	for(int i=0,u,v;i<s[x].size();i++){
    	   for(int j=0;j<s[y].size();j++){
    	   	   u=s[x][i].first,v=s[y][j].first;
    	   	   ans=min(ans,dist[u][v]+s[x][i].second+s[y][j].second);
		   }
	    }
	    printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
