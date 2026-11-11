#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=505,maxm=2e4+5;
const ll INF=1e18;
int c,n,m,d,q;
ll w[maxm];
struct node{
	int pos;
	ll val;
};
struct dot{
	int pos,dep;
	ll val;
	bool operator < (const dot &other)const{
		return val>other.val;
	}
};
vector<node>a[maxn];
unordered_set<int>s[maxn];
ll val[maxm][maxn],dis[maxm][maxn];
ll bfs(int u,int v){
	priority_queue<dot>pq;
	ll res=1e18;
	for(int i=1;i<=n;i++){
		if(s[i].find(u)!=s[i].end()){
			pq.push({u,i,val[u][i]});
		}
	}
	while(!pq.empty()){
		dot tmp=pq.top();
		pq.pop();
//		cout<<tmp.pos<<' '<<tmp.dep<<' '<<tmp.val<<"\n";
		if(tmp.val>dis[tmp.pos][tmp.dep])continue;
		if(tmp.pos==v){
			res=min(res,tmp.val+val[v][tmp.dep]);
			continue;
		}
		for(auto i:a[tmp.dep]){
			if(dis[i.pos][tmp.dep]>tmp.val){
				dis[i.pos][tmp.dep]=tmp.val;
				pq.push({i.pos,tmp.dep,tmp.val});
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i].find(tmp.pos)==s[i].end())continue;
			if(dis[tmp.pos][i]>tmp.val+val[tmp.pos][tmp.dep]+val[tmp.pos][i]){
				dis[tmp.pos][i]=tmp.val+val[tmp.pos][tmp.dep]+val[tmp.pos][i];
				pq.push({tmp.pos,i,dis[tmp.pos][i]});
			}
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			ll u,v;cin>>u>>v;
			a[i].push_back({(int)u,v});
			val[u][i]=v;
			s[i].insert(u); 
		}
	}
	while(q--){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=INF;
			}
		}
		int x,y;cin>>x>>y;
		ll ans=w[x]+w[y];
		ll res=bfs(x,y);
		cout<<ans+res<<"\n";
	}
	return 0;
}
