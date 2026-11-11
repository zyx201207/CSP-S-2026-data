#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k,u,v,mn=LLONG_MAX;
vector<ll> b;
vector<vector<ll>> a;
void dfs(ll i=0){
	if(i==k){
		ll mx=LLONG_MIN,s=0;
		vector<char> f(n+1,0);
		for(int i=0;i<b.size();i++) f[b[i]]=1;
		for(int i=0;i<b.size();i++){
			if(!f[b[i]]) continue;
			s++;
			queue<ll> q;
			q.push(b[i]);
			while(!q.empty()){
				ll p=q.front();
				q.pop();
				for(auto &v:a[p]){
					if(f[v]){
						f[v]=0;
						q.push(v);
					}
				}
			}
		}
		if(s>2) return;
		f.assign(n+1,1);
		queue<ll> q,q1;
		for(int i=0;i<b.size();i++) q.push(b[i]),q1.push(0),f[b[i]]=0;
		while(!q.empty()){
			ll p=q.front(),s=q1.front();
			q.pop();
			q1.pop();
			mx=max(mx,s);
			for(auto &v:a[p]){
				if(f[v]){
					f[v]=0;
					q.push(v);
					q1.push(s+1);
				}
			}
		}
		mn=min(mn,mx);
	}
	for(int j=b.empty()?1:b.back()+1;j<=n;j++){
		b.push_back(j);
		dfs(i+1);
		b.pop_back();
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		mn=LLONG_MAX;
		a.assign(n+1,vector<ll>());
		for(int i=1;i<n;i++){
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs();
		cout<<mn<<'\n';
	}
	return 0;
}
