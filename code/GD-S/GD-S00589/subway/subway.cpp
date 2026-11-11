#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll c,n,m,d,q,k,s,t,w[N],dst[N];
bool vis[N];
struct Node{ll x,y;};
vector<Node> ve[N];
struct node{
	ll x,dst;
	bool operator<(const node&b)const{
		return dst>b.dst;
	}
};
void dij(){
	priority_queue<node> q;
	q.push({s,0});
	dst[s]=w[s];
	while(q.size()){
		node h=q.top();q.pop();
		if(vis[h.x]) continue;
		vis[h.x]=true;
		for(ll i=0;i<ve[h.x].size();i++){
			ll k=ve[h.x][i].x,tm=ve[h.x][i].y;
			if(dst[k]>dst[h.x]+tm){
				dst[k]=dst[h.x]+tm;
				q.push({k,dst[h.x]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll x,t;cin>>x>>t;
			ve[j].push_back({x,t});
			ve[x].push_back({j,t});
		}
	}
	while(q--){
		for(ll i=1;i<=N;i++) dst[i]=1e9,vis[i]=false;
		cin>>s>>t;
		dij();
		cout<<dst[t]+w[t]<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

