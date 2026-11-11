#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define up(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define dn(i,a,b,c) for(ll i=a;i>=b;i-=c)

using namespace std;
const ll N=510;
ll c,n,m,d,q;
ll w[N];
ll k;
ll a[N][N];
ll t[N][N];
ll x,y;
vector<pair<ll,ll> > v[N];
vector<ll> ve[N];
ll vis[N];
ll ans=0;
ll cmp[N];
ll gm;
inline void bfs(){
	up(i,1,n,1)vis[i]=0;
	queue<pair<ll,ll> > q;
	q.push({x,0});
	while(!q.empty()){
		ll now=q.front().first;
		ll num=q.front().second;
		if(now==y)ans=min(ans,num);
		q.pop();
		vis[now]=1;
		for(auto i:ve[now]){
			for(auto j:v[i]){
				if(vis[j.first])continue;
				if(cmp[j.first]>1) gm=t[now][j.first]+t[j.first][j.first];
				else gm=0;
				q.push({j.first,num+j.second+gm});
			}
		}
	}
	cout<<ans+w[x]+w[y]<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	up(i,1,m,1)cin>>w[i];
	up(i,1,n,1){
		cin>>k;
		up(j,1,k,1){
			cin>>a[i][j]>>t[i][j];
			v[i].push_back({j,t[i][j]});
			ve[a[i][j]].push_back(i);
			cmp[a[i][j]]++;
		}
	}
	while(q--){
		cin>>x>>y;
		ans=LLONG_MAX;
		bfs();
	}
	return 0;
}
