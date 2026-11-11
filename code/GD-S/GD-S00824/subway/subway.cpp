#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
vector<ll>k;
vector<vector<ll>>sta;
vector<vector<ll>>dis;
ll solve(ll x,ll fi,ll ti){
	if(x==fi){return ti;}
	for(int i=1;i<=m;i++){
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	ll k1,k2,k3;
	for(int i=1;i<=n;i++){
		cin>>k1;
		k.push_back(k1);
		for(int i=1;i<=k1;i++){
			cin>>k2>>k3;
			sta[i].push_back(k2);
			dis[i].push_back(k3);
		}
	}
	ll st,fi;
	while(q--){
		cin>>st>>fi;
		cout<<solve(st,fi,0)<<" ";
	}
	return 0;
} 
