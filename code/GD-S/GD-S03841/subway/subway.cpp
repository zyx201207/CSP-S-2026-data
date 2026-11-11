#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long,int> 
#define ll long long
const ll INF=1000000000000009;
int c,n,m,d,q;
struct node{
	ll to,l;
};
struct xw{
	int x,y,id;
};
vector<node> v[1001000]; 
bool cmp(xw x,xw y){
	return x.x<y.x;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<ll> w(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k; 
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[m+i].push_back({a,t});
			v[a].push_back({m+i,t});
		}
	}
	
	vector<xw> jl(q);
	for(int i=0;i<q;i++){
		cin>>jl[i].x>>jl[i].y;
		if(jl[i].x>jl[i].y)swap(jl[i].x,jl[i].y);
		jl[i].id=i;
	}
	sort(jl.begin(),jl.end(),cmp);
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	vector<ll> dp(m+n+10),ans(q);
	int lt;
	for(int i=0;i<q;i++){
		int s=jl[i].x,t=jl[i].y;
		if(i>0&&lt==s){
			ans[jl[i].id]=w[s]+w[t]+dp[t];
			continue;
		}
		lt=s;
		fill(dp.begin(),dp.end(),INF);
		dp[s]=0;
		pq.push({0,s});
		while(!pq.empty()){
			pii t=pq.top();pq.pop();
			int u=t.second;ll l=t.first;
			if(l!=dp[u])continue;
			for(auto p:v[u]){
				if(dp[p.to]>l+p.l){
					dp[p.to]=l+p.l ;
					pq.push({dp[p.to],p.to});
				}
			}
		}
		ans[jl[i].id]=w[s]+w[t]+dp[t];
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}

