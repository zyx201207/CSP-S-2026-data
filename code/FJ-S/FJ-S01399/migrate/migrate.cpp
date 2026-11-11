#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=5005;
const ll inf=1e18;
ll n,d,a[N],b[N],dis[N],qwq[N],sqwq[N];bool vis[N];
vector<ll> G[N];
void bfs(ll s){
	for(ll i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
	queue<ll> q;q.push(s),dis[s]=0,vis[s]=1;
	while(!q.empty()){
		ll u=q.front();q.pop();
		for(auto v:G[u]){
			if(vis[v]) continue;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1,vis[v]=1;
				q.push(v);
			}
		}
	}
}
ll query(ll l,ll r){
	return (l>r?0:sqwq[r]-sqwq[l-1]);
}
void solve(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i!=j&&abs(a[j]-a[i])<=d){
				G[i].push_back(j);
			}
		}
	}ll ans=0;
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,res=i;
		while(l<=r){
			ll md=(l+r)>>1;
			if(a[i]-a[md]<=d) r=md-1,res=md;
			else l=md+1;
		}b[i]=res;
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++){
//			if(i!=j&&abs(a[j]-a[i])<=d) cout<<i<<" "<<j<<endl;
//		} 
//	}
	for(ll u=1;u<=n;u++){
		bfs(u);
//		for(ll v=u+1;v<=n;v++){
////			ll cnt=0;
//			for(auto p:G[v]){
//				if(dis[p]==dis[v]-1&&p<v) qwq[v]++;
//			}
//		}
		qwq[u]=1,sqwq[u]=1;
		for(ll v=u+1;v<=n;v++){
			ll l=max(b[v],u),r=v-1,res=v,al=0,ar=0;
//			cout<<v<<":";
//			for(ll i=l;i<=r;i++) cout<<dis[i]<<" ";
//			cout<<endl;
			while(l<=r){
				ll md=(l+r)>>1;
				if(dis[md]>=dis[v]-1) r=md-1,res=md;
				else l=md+1;
			}
			al=res;
			l=max(b[v],u),r=v-1,res=v;
			while(l<=r){
				ll md=(l+r)>>1;
				if(dis[md]<=dis[v]-1) l=md+1,res=md;
				else r=md-1;
			}
			ar=res;
			if((al==0)||(ar==0)) continue;
			if(dis[al]!=dis[v]-1||dis[ar]!=dis[v]-1) continue; 
			qwq[v]=query(al,ar);
			sqwq[v]=sqwq[v-1]+qwq[v];
//			for(auto p:G[v]){
////				if(u<=p&&p<v) cout<<v<<":"<<dis[p]<<endl;
//				if(dis[p]==dis[v]-1&&u<=p&&p<v) qwq[v]+=qwq[p];
//			}
			if(qwq[v]==2) ans++; 
		}
//		cout<<endl;
		for(ll i=1;i<=n;i++) qwq[i]=sqwq[i]=0;
	}
	cout<<ans<<endl;
	for(ll i=1;i<=n;i++) G[i].clear();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll lzyakioi,T;cin>>lzyakioi>>T;
	while(T--) solve();
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
