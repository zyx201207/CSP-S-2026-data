#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int kM = 5e5 + 10;

int c,n,m,d,q;
int w[kM];
vector<pair<int,ll>> g[kM];
bool vt[kM];

ll f(int s,int e){
	priority_queue<pair<int,ll>,vector<pair<int,ll>>,greater<pair<int,ll>>> pq;
	memset(vt,0,sizeof(vt));
	vt[s] = true;
	for(pair<int,ll> v:g[s]){
		pq.push({v.first,v.second});
	}
	while(!pq.empty()){
		auto now = pq.top();pq.pop();
		int u = now.first;
		ll st = now.second;
		if(u == e){
			return st;
		}
		for(auto nv : g[u]){
			if(nv.first == u || vt[nv.first])continue;
			vt[nv.first] = true;
			pq.push({nv.first,nv.second+st});
		}
	}
	return -1;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k;cin>>k;
		vector<int> a;
		vector<int> t;
		for(int j=0;j<k;j++){
			int x;ll y;cin>>x>>y;
			a.push_back(x);
			t.push_back(y);
		}
		int l = a.size();
		for(int ki=0;ki<l;ki++){
			for(int kj=ki+1;kj<l;kj++){
				g[a[ki]].push_back({a[kj],t[ki]+t[kj]});
				g[a[kj]].push_back({a[ki],t[ki]+t[kj]});
			}
		}
	}
	
	while(q--){
		int s,e;cin>>s>>e;
		cout<<ll(w[s])+ll(w[e])+f(s,e)<<'\n';
	}
	return 0;
}
