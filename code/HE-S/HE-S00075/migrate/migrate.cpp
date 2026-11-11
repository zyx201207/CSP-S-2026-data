#include<bits/stdc++.h>
#include<set>
#define ll long long
#define up(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define dn(i,a,b,c) for(ll i=a;i>=b;i-=c)

using namespace std;
const ll N=2e6+10;
ll c,t;
ll n,d;
ll x[N];
ll s[N];
set<ll> minn[N];
vector<ll> ve[N];
bool vis[N];
ll ans=0;
inline void bfs(ll now){
	up(i,1,n,1)s[i]=LLONG_MAX,vis[i]=0;
	queue<ll>q;
	q.push(now);
	s[now]=0;
	vis[now]=1;
	while(!q.empty()){
		ll x=q.front();
		q.pop();
		vis[x]=1;
		for(auto i:ve[x]){
			if(vis[i]==1)continue;
			if(s[x]+1<s[i]){
				minn[i].clear();
				s[i]=s[x]+1;
			}
			if(s[x]+1==s[i]){
				minn[i].insert(x);
			}
			q.push(i);
		}
	}
	up(i,1,n,1){
		if(minn[i].size()==2){
			ans++;
		}
		minn[i].clear();
	}
}
inline void solve(){
	ans=0;
	cin>>n>>d;
	up(i,1,n,1)ve[i].clear();
	if(d==1){
		cout<<0<<endl;
		return;
	}
	up(i,1,n,1){
		cin>>x[i];
	}
	up(i,1,n,1){
		up(j,i,n,1){
			if(i==j)continue;
			if(x[j]-x[i]<=d){
				ve[i].push_back(j);
			}
		}
	}
	up(i,1,n,1){
		bfs(i);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
