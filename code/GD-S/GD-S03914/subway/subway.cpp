#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],v[500005],ans=LONG_LONG_MAX;
vector<pair<int,int> >e[500005];
vector<int>s[20]; 
void dfs(int x,int s,int t){
	if(x==t){
		ans=min(ans,s);
		return ;
	} 
	v[x]=1;
	for(auto i:e[x]){
		if(v[i.first])continue;
		dfs(i.first,s+i.second,t);
	}
	v[x]=0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
			int k,p,q,tp,tq;
			cin>>k;
			if(k==1){
				int o,p;cin>>o>>p;continue;
			}
			cin>>p>>tp>>q>>tq;
			e[p].push_back({q,tq+tp});
			e[q].push_back({p,tp+tq});
		}
		while(q--){
			int x,y;
			ans=LONG_LONG_MAX;
			cin>>x>>y;
			dfs(x,0,y);
			cout<<ans+w[x]+w[y]<<'\n';
		}
	}else if(c>=20&&c<=21){
		int k;
		cin>>k;
		while(k--){
			int p,t;
			cin>>p>>t;
			e[p].push_back({1,t});
		}
		cin>>k;
		while(k--){
			int p,t;
			cin>>p>>t;
			if(!e[p].empty()){
				ans=min(ans,e[p][0].second+t);
			}
			v[p]=t;
			e[p].push_back({0,ans});
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			if(e[x][0].first==e[y][0].first||(v[x]&&v[y])){
				cout<<ans+min(e[x][0].second+v[y],e[y][0].second+v[x])<<'\n';
			}else
			cout<<w[x]+w[y]+ans+min(e[x][0].second+v[y],e[y][0].second+v[x])<<'\n';
		}
	}
	return 0;
}
