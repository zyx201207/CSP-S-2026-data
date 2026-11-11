#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN=2010;
ll c,n,m,d,t,k,e_t[MAXN],s_t[510][MAXN];

vector<ll> v[510],bh[MAXN];

struct stu{
	ll x,z,t;
};

queue<stu> q;
void bfs(ll s,ll e){
	ll mii=LLONG_MAX,mi[510][MAXN];
	for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++) mi[i][j]=LLONG_MAX;
	while(!q.empty()) q.pop();
	for(ll x:bh[s]){
		q.push({x,s,s_t[x][s]});
		mi[x][s]=s_t[x][s];
	}
	while(!q.empty()){
		ll x=q.front().x;
		ll z=q.front().z;
		ll t=q.front().t;
		q.pop();
		if(z==e){
			mii=min(mii,t+s_t[x][z]);
			continue;
		}
		for(ll nz:v[x]){
			if(nz!=z){
				if(mi[x][nz]>t){
					q.push({x,nz,t});
					mi[x][nz]=t;
				}
			}
		}
		for(ll nx:bh[z]){
			if(nx!=x){
				if(mi[nx][z]>t+s_t[x][z]+s_t[nx][z]){
					q.push({nx,z,t+s_t[x][z]+s_t[nx][z]});
					mi[nx][z]=t+s_t[x][z]+s_t[nx][z];
				}
			}
		}
	}
	cout<<mii+e_t[s]+e_t[e]<<'\n';
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>t;
	for(ll i=1;i<=m;i++) cin>>e_t[i];
	for(ll i=1;i<=n;i++){
		cin>>k;
		while(k--){
			ll s,e;
			cin>>s>>e;
			v[i].push_back(s);
			bh[s].push_back(i);
			s_t[i][s]=e;
		}
	}
	while(t--){
		ll s,e;
		cin>>s>>e;
		bfs(min(s,e),max(s,e));
	}
	return 0;
}
