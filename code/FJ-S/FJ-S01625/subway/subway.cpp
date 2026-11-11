#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505,M=5e5+5;
ll c,n,m,d,q;
ll w[M];
struct node{
	ll id,t;
};
vector<node>e[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int i=1;i<=k;i++){
			ll h,t;cin>>h>>t;
			e[h].push_back({i,t});
		}
	}
	while(q--){
		ll x,y;cin>>x>>y;
		queue<node>q;
		q.push({x,0});
		while(!q.empty()){
			auto start=q.front();q.pop();
			for(auto s:e[x]){
				ll h=s.id,t=s.t;
			}
		}
	}
	return 0;
} 
