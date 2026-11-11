#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,x,y,w[500005],k[505],gg[505][505],s=0,ans=0;
bool _34=true,_56=true;
vector<vector<ll>> a,t,f,su;
struct node{
	ll n;
	ll w;
	bool operator<(const node &o) const{
		return w>o.w;
	}
};
vector<vector<node>> g;
ll dist(ll x,ll y){
	vector<ll> ans(n+1,LLONG_MAX);
	vector<char> b(n+1,1);
	priority_queue<node> q;
	q.push({x,0});
	ans[x]=0;
	b[x]=0;
	while(!q.empty()){
		node p=q.top();
		q.pop();
		if(p.n==y) break;
		if(p.w>ans[p.n]) continue;
		b[p.n]=0;
		for(auto &v:g[p.n]){
			if(b[v.n]&&ans[v.n]>ans[p.n]+v.w){
				ans[v.n]=ans[p.n]+v.w;
				q.push({v.n,ans[v.n]});
			}
		}
	}
	return ans[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	a.resize(n+1);
	g.resize(n+1);
	t.resize(n+1);
	su.resize(m+1);
	f.resize(n+1,vector<ll>(m+1,LLONG_MAX));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		_34=_34&&k[i]<=2;
		_56=_56&&k[i]==n;
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j],_56=_56&&t[i][j]==t[1][1],f[i][a[i][j]]=t[i][j],su[a[i][j]].push_back(i);
	}
	if((c>=7&&c<=11)||_34){
		vector<vector<node>> g(m+1);
		for(int i=1;i<=n;i++){
			if(k[i]==2){
				g[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
				g[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
			}
		}
		while(q--){
			cin>>x>>y;
			vector<ll> ans(m+1,LLONG_MAX);
			vector<char> b(m+1,1);
			priority_queue<node> q;
			q.push({x,0});
			ans[x]=0;
			b[x]=0;
			while(!q.empty()){
				node p=q.top();
				q.pop();
				if(p.n==y) break;
				if(p.w>ans[p.n]) continue;
				b[p.n]=0;
				for(auto &v:g[p.n]){
					if(b[v.n]&&ans[v.n]>ans[p.n]+v.w){
						ans[v.n]=ans[p.n]+v.w;
						q.push({v.n,ans[v.n]});
					}
				}
			}
			cout<<ans[y]+w[x]+w[y]<<'\n';
		}
	} else{
		for(int i=1;i<=n;i++){
			gg[i][i]=LLONG_MAX;
			for(int j=i+1;j<=n;j++){
				gg[i][j]=gg[j][i]=LLONG_MAX;
				for(int l=1;l<=k[i];l++){
					if(f[j][a[i][l]]!=LLONG_MAX){
						gg[i][j]=gg[j][i]=min(gg[i][j],t[i][l]+f[j][a[i][l]]);
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(gg[i][j]!=LLONG_MAX){
					g[i].push_back({j,gg[i][j]});
				}
			}
		}
		while(q--){
			cin>>x>>y;
			ll mn=LLONG_MAX;
			for(int i=0;i<su[x].size();i++){
				for(int j=0;j<su[y].size();j++){
					mn=min(mn,dist(su[x][i],su[y][j])+f[su[x][i]][x]+f[su[y][j]][y]);
				}
			}
			cout<<mn+w[x]+w[y]<<'\n';
		}
	}
	return 0;
}
