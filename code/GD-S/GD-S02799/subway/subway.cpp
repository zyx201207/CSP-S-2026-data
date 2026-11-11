#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
class dat{
	public:
		ll id,w;
};
ll c,n,m,d,q,w[500010],dist[510][510];
vector<ll>ids[500010];
vector<dat>line[500010];
ll ch(ll cur,ll lineid){
	for(dat x:line[cur]){
		if(x.id==lineid)return x.w;
	}
	return -1;
}
ll solve(ll from,ll to){
	ll ans=inf;
	for(dat x:line[from]){
		for(dat y:line[to])ans=min(ans,w[from]+x.w+dist[x.id][y.id]+y.w+w[to]);
	}
	return ans;
}
int main(){
	memset(dist,0x3f,sizeof(dist));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1,k;i<=n;i++){
		dist[i][i]=0;
		cin>>k;
		for(ll f=1,to,x;f<=k;f++){
			cin>>to>>x;
			line[to].push_back({i,x});
			for(ll j:ids[to]){
				dist[j][i]=min(dist[j][i],x+ch(to,j));
				dist[i][j]=min(dist[i][j],x+ch(to,j));
			}
			ids[to].push_back(i);
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			if(i==k)continue;
			for(ll j=1;j<=n;j++){
				if(j==k||dist[i][k]==inf||dist[k][j]==inf)continue;
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	ll x,y;
	while(q--){
		cin>>x>>y;
		cout<<solve(x,y)<<'\n';
	}
	return 0;
}
