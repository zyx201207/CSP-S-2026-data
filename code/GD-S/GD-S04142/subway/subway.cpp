#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
vector<bool> l;
//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
vector<vector<pair<ll,ll>>> a;
ll dfs(ll st,ll end,ll time){
//	bool flag = 1;
//	for(int i = 0;i <= n;i++){
//		if(l[i] == 0){
//			flag = 0;
//		}
//	}
//	if(flag)return time;
//	for(ll i = 1;i<=n;i++){
//		if(i == st) continue;
//		for(ll j = 0;j < a[i].size();j++){
//			if(a[i][j].first == end){
//				return time;
//			}
//		}
//		for(ll j = 0;j < a[i].size();j++){
//			if(a[i][j].first == a[st][j].first && l[i] == 0){
//				l[i] == 1;
//				dfs(i,end,(time+a[st][j].second+a[i][j].second));
//				l[i] == 0;
//			}
//		}
//	}
	return LLONG_MAX;
}
int main(){
	freopen("subway1.in","r",stdin);
	cin>>c>>n>>m>>d>>q;
	a.resize(n+5);
	vector<vector<pair<ll,ll>>> mp;
	ll w[m+5];
	for(ll i = 1;i <= m;i++){
		cin>>w[i];
	}
	for(ll i = 1;i <= n;i++){
		ll k;
		cin>>k;
		for(ll j = 1;j <= k;j++){
			ll a1,t1;
			cin>>a1>>t1;
			a[i].push_back({a1,t1});
		}
	}
	l.resize(n);
	for(ll i =0;i < q;i++){
		ll bstart=0,bend=0;
		cin>>bstart>>bend;
		ll ans = w[bstart]+w[bend];
		ll mint = LLONG_MAX;
//		for(ll i = 1;i < m;i++){
//			for(ll j = 1;j < a.size();j++){
//				if(a[i][j].first == bstart){
//					ll op = dfs(i,bend,0);
//					mint = min(mint,op);
//				}
//			}
//		}
		cout<<ans<<endl;
	}
	//freopen("subway.ans","w",stdout);
	return 0;
}
