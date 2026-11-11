#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
ll c,n,m,d,q;
vector<pll>e[1000005];
vector<pll>stmp;
ll s[505][505];
ll w[500005];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
//		e[i].push_back({i+m,w[i]});
//		e[i+m].push_back({i,w[i]});
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll aij,tij;
			cin>>aij>>tij;
			e[aij].push_back({m+i,tij});
			e[m+i].push_back({aij,tij});
			
		}
	}
	
	
//	for(ll i=1;i<=m*2+n;i++){
//		cout<<i<<':';
//		for(auto v:e[i]){
//			cout<<v.first<<' ';
//		}cout<<'\n';
//	}
	
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			s[i][j]=1e16;
			if(i==j)s[i][j]=0;
		}
	}
	
	for(ll i=1;i<=m;i++){
		stmp.clear();
		for(auto u:e[i]){
			if(u.first<=m)continue;
			stmp.push_back(u);
		}
		for(auto j:stmp){
			for(auto k:stmp){
				if(j.first==k.first)continue;
				
				auto &sjk=s[j.first-m][k.first-m];
				auto &skj=s[k.first-m][j.first-m];
				
				sjk=min(sjk,j.second+k.second);
				skj=min(skj,j.second+k.second);
				
			}
		}
	}
	
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++){
//			cout<<s[i][j]<<' ';
//		}cout<<'\n';
//	}
	
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(s[i][j]>s[i][k]+s[k][j]){
					s[i][j]=s[i][k]+s[k][j];
				}
			}
		}
	}
	
	for(ll i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		
		ll ans=1e16;
		
		for(auto st:e[x]){
			for(auto ed:e[y]){
				ans=min(ans,st.second+ed.second+s[st.first-m][ed.first-m]);
			}
		}
		
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	
	return 0;
}