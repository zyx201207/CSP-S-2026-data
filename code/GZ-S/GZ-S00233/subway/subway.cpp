//GZ-S00233 遵义市第四中学 毛俊程 
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const int MAXN=5e5+505;
int c,n,m,d,Q,cnt,a1[MAXN],a2[MAXN],k1,k2,s[MAXN],bel1[MAXN],bel2[MAXN];
ll dist[MAXN],w[MAXN],ans[MAXN],t1[MAXN],t2[MAXN];
vector<pair<int,ll> > g[MAXN];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
struct node{
	int x,y,id;
}p[MAXN];
bool comp(node x,node y){
	return x.x<y.x;
}
void dij(int z){
	dist[z]=0;
	q.push({dist[z],z});
	while(!q.empty()){
		pair<ll,int>x=q.top();
		q.pop();
		ll d=x.first;
		int u=x.second;
		if(d>dist[u]) continue;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first;
			ll w=g[u][i].second;
			if(dist[u]!=INT_MAX&&dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	if(n<=2){
		ll mn=LLONG_MAX;
		for(int i=1;i<=m;i++) cin>>w[i];
		cin>>k1;
		for(int i=1;i<=k1;i++){
			cin>>a1[i]>>t1[i];
			s[a1[i]]++;
			bel1[a1[i]]=1;
		}
		cin>>k2;
		for(int i=1;i<=k2;i++){
			cin>>a2[i]>>t2[i];
			s[a2[i]]++;
			bel2[a2[i]]=1;
			if(s[a2[i]]==2) mn=min(mn,t1[a2[i]]+t2[a2[i]]);
		}
		for(int i=1;i<=Q;i++){
			int x,y;
			cin>>x>>y;
			if(bel1[x]&&bel1[y]) cout<<w[x]+w[y]+t1[x]+t1[y]<<'\n';
			else if(bel2[x]&&bel2[y]) cout<<w[x]+w[y]+t2[x]+t2[y]<<'\n';
			else if(bel1[x]&&bel2[y]) cout<<w[x]+w[y]+t1[x]+t2[y]+mn<<'\n';
			else cout<<w[x]+w[y]+t2[x]+t1[y]+mn<<'\n';
		}
		return 0;
	}
	cnt=m+1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			ll t;
			cin>>a>>t;
			g[cnt].push_back({a,t});
			g[a].push_back({cnt,t});
		}
		cnt++;
	}
	for(int i=1;i<=Q;i++){
		int x,y;
		cin>>x>>y;
		p[i].x=x;
		p[i].y=y;
		p[i].id=i;
	}
	sort(p+1,p+Q+1,comp);
	int v=0;
	for(int i=1;i<=Q;i++){
		if(v==p[i].x){
			ans[p[i].id]=dist[p[i].y]+w[p[i].x]+w[p[i].y];
		}
		else{
			v=p[i].x;
			for(int j=1;j<=cnt;j++){
				dist[j]=LLONG_MAX;
			}
			while(!q.empty()) q.pop();
			dij(p[i].x);
			ans[p[i].id]=dist[p[i].y]+w[p[i].x]+w[p[i].y];
		}
	}
	for(int i=1;i<=Q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
