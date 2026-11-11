#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pll pair<long,long>
ll ed[5100][5100];
ll w[5000010];
ll k[510];
struct sss{
	ll id;
	ll t;
};
vector<sss> a[5000010];
ll c,n,m,d,q;
ll mit[5100][5100];
bool b[5000010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	ll a1,t;
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a1>>t;
			a[a1].push_back({i,t});
		}
	}
//	for(ll i=1;i<=m;i++){
//		cout<<i<<" ";
//		for(auto v:a[i]){
//			cout<<v.id<<" "<<v.t<<" ";
//		}
//		cout<<endl;
//	}
	for(ll i=1;i<=m;i++){
		for(auto u:a[i]){
			for(auto v:a[i]){
				if(u.id==v.id) continue;
				if(ed[u.id][v.id]==0||ed[u.id][v.id]>u.t+v.t){
					ed[u.id][v.id]=u.t+v.t;
					ed[v.id][u.id]=u.t+v.t;
				}
			}
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++){
//			cout<<ed[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(ll fr=1;fr<=n;fr++){
		b[fr]=true;
		priority_queue<pll,vector<pll>,greater<pll> > q;
		for(ll i=1;i<=n;i++){
			if(ed[fr][i]!=0) q.push({ed[fr][i],i});
		}
		while(!q.empty()){
			ll now=q.top().second;
			ll nowt=q.top().first;
			q.pop();
			if(b[now]) continue;
			mit[fr][now]=nowt;
			b[now]=true;
			for(ll j=1;j<=n;j++){
				if(!b[j]&&ed[now][j]!=0) q.push({mit[fr][now]+ed[now][j],j});
			} 
		}
		memset(b,0,sizeof(b));
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++){
//			cout<<mit[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	ll u,v;
	for(ll i=1;i<=q;i++){
		cin>>u>>v;
		ll sum,mi=LONG_LONG_MAX;
		for(auto from:a[u]){
			for(auto to:a[v]){
				sum=mit[from.id][to.id]+from.t+to.t;
//				cout<<from.id<<" "<<to.id<<" ";
//				cout<<sum<<" ";
				mi=min(sum,mi);
//				cout<<mi<<endl;
			}
		}
		mi+=w[u]+w[v];
		cout<<mi<<endl;
//		cout<<"__________________________\n";
	}
	return 0;
}
