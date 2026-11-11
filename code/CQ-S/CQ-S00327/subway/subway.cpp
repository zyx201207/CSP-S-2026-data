#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define in inline
const ll maxn=5e5+500;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll c,n,m,d,q;
ll w[maxn];
vector<pair<ll,ll>> node[maxn];
vector<pair<ll,ll>> sb[maxn];
priority_queue<ll,vector<ll>,greater<ll>> t;
bool b[maxn];
ll ans[maxn];
void di(ll x,ll y){
	memset(ans,0x3f,sizeof(ans));
	memset(b,0,sizeof(b));
	ans[x]=w[x];
	b[x]=1;
	t.push(x);
	while(!t.empty()){
		ll u=t.top();
		t.pop();
		for(auto i:node[u]){
			ll v=i.first;
			ll p=i.second;
			if(ans[u]+p<ans[v]){
				ans[v]=ans[u]+p;
				if(!b[v]){
					b[v]=1;
					t.push(v);
				}
			}
		}
	}
}void di1(ll x,ll y){
	memset(ans,0x3f,sizeof(ans));
	memset(b,0,sizeof(b));
	ans[x]=w[x];
	b[x]=1;
	t.push(x);
	while(!t.empty()){
		ll u=t.top();
		t.pop();
		for(auto i:sb[u]){
			ll v=i.first;
			ll p=i.second;
			if(ans[u]+p<ans[v]){
				ans[v]=ans[u]+p;
				if(!b[v]){
					b[v]=1;
					t.push(v);
				}
			}
		}
	}
}void bfs(ll x,ll y){
	queue<pair<ll,ll>> r;
	b[x]=1;
	r.push({x,w[x]});
	memset(ans,0,sizeof(ans));
	memset(b,0,sizeof(b));
	ans[x]=w[x];
	while(!r.empty()){
		ll u=r.front().first;
		ll o=r.front().second;
		r.pop();
		for(auto i:node[u]){
			ll v=i.first;
			ll va=i.second;
			if(!b[v]){
				b[v]=1;
				ans[v]=o+va;
				r.push({v,o+va});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		for(int j=1;j<=x;j++){
			ll y,z;
			cin>>y>>z;
			node[y].push_back({i+m,z});
			node[m+i].push_back({y,z});
		}
	}if(c>=20 and c<=21){
		ll t1=0;
		ll _min=inf;
		for(auto i:node[1]){
			_min=min(_min,i.second);
		}
		t1+=_min;
		_min=inf;
		for(auto i:node[2]){
			_min=min(_min,i.second);
		}
		t1+=_min;
		for(int i=1;i<=q;i++){
			ll x,y;
			cin>>x>>y;
			cout<<t1+w[1]+w[2]<<endl;
		}
		return 0;
	}if(c>=9 and c<=11){
		for(int i=m+1;i<=n+m;i++){
			ll u,v,o=0,z=0;
			for(auto j:node[i]){
				if(z==0){
					u=j.first;
					o=j.second;
				}else{
					v=j.first;
					o+=j.second;
				}
			}
			sb[u].push_back({v,o});
			sb[v].push_back({u,o});
		}for(int i=1;i<=q;i++){
			ll x,y;
			cin>>x>>y;
			di1(x,y);
			cout<<ans[y]+w[y]<<endl;
		}
		return 0;
	}if(c>=12 and c<=16){
		for(int i=1;i<=n;i++){
			ll x,y;
			cin>>x>>y;
			bfs(x,y);
			cout<<ans[y]+w[y]<<endl;
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		di(x,y);
//		for(int i=1;i<=m+n;i++){
//			cout<<ans[i]<<' ';
//		}cout<<endl;
		cout<<ans[y]+w[y]<<endl;
	}
	return 0;
}

