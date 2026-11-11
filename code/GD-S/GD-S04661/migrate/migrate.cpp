#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int kM = 2e6 + 10;

int C,T,n;
ll d,x[kM];

ll f(int s,int e){
	ll res = 0;
	queue<pair<int,ll>> q;
	q.push({s,0LL});
	ll mi = 1e9;
	while(!q.empty()){
		auto k = q.front();q.pop();
		int u = k.first;
		ll s = k.second;
		if(u==e){
			mi = min(mi,s);
			if(s==mi){
				res++;
			}
			else{
				break;
			}
		}
		for(int i=u+1;i<=e;i++){
			if(x[i] - x[u] <= d){
				q.push({i,s+1});
			}
		} 
	}
	return res;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}		
		ll ans = 0;
		for(int s=0;s<n;s++){
			for(int e=0;e<n;e++){
				if(s==e)continue;
				if(f(s,e) == 2)ans++;
			}
		}
		cout<<ans<<'\n';
	}	
	return 0;
}
