#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t[509][20009],a[509][20009],k[509],w[500009],mi[500009],c,n,m,d,q,ans;
vector<pair<ll,ll> > v[20009];
void bfs(ll start,ll fish){
	queue<pair<ll,ll> > q;
	for(ll i=0;i<v[start].size();i++){
		q.push({i,w[start]});
	}
	while(!q.empty()){
		ll x=q.front().first,sum=q.front().second;
		q.pop();
		if(sum>=mi[x]){
			if(x==fish){
				ans=min(ans,mi[x]+w[x]);	
			}
			continue;
		}else{
			mi[x]=sum;
		}
		if(x==fish){
			ans=min(ans,mi[x]+w[x]);
			continue;		
		}
		for(ll i=0;i<v[x].size();i++){
			pair<ll,ll> node=v[x][i];
			for(ll j=node.second+1;j<=k[node.first];j++){
				q.push({a[node.first][j],sum+t[node.first][j]+t[node.first][node.second]});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		scanf("%lld" ,&w[i]);
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(ll j=1;j<=k[i];j++){
			scanf("%lld %lld",&a[i][j],&t[i][j]);
			v[a[i][j]].push_back({i,j});
		}
	}
	ll x,y;
	while(q--){
		ans=LLONG_MAX;
		memset(mi,0x3f,sizeof(mi));
		cin>>x>>y;
		bfs(x,y);
		cout<<ans<<"\n";	
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
