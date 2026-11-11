#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
ll c,t,n,k,dep[N],f[N],cntdep[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		vector<ll> graph[n+5];
		bool fa = 1;
		for(int i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			if(u != i || v != i+1)fa = 0;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for(int i=1;i<=n;i++)dep[i] = 0,f[i] = 0;
		queue<ll> q;
		q.push(1);
		f[1] = 0;
		ll mmax = 0;
		while(!q.empty()){
			ll u = q.front();
			q.pop();
			for(auto kk:graph[u]){
				if(kk == f[u])continue;
				q.push(kk);
				f[kk] = u;
				dep[kk] = dep[u]+1;
				cntdep[dep[kk]]++;
				mmax = max(dep[kk],mmax);
			}
		}
		if(fa == 1){
			ll ans = (mmax-k+1) / 2;
			cout<<ans<<'\n';
		}
		else if(k == 2){
			cout<<(mmax+2) / 3<<'\n';
		}
		else{
			cout<<((mmax+2)/3 + 3) / 4<<'\n';
		}
	}

	return 0;
}
