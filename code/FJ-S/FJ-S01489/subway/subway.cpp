#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const ll maxn=5e5+5;
const ll inf=1e18;
struct Node{
	ll p,d;
};
ll c,n,m,d,q;
ll w[maxn];
vector <Node> st[maxn];
ll edge[505][505];
ll dp[505][505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++)edge[i][j]=dp[i][j]=inf;
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			for(Node e:st[a]){
				edge[e.p][i]=min(edge[e.p][i],t+e.d);
				edge[i][e.p]=edge[e.p][i];
				dp[i][e.p]=dp[e.p][i]=edge[e.p][i];
			}
			st[a].push_back({i,t});
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll j=1;j<=n;j++){
			for(ll i=j;i<=n;i++){
				dp[j][i]=dp[i][j]=min(dp[i][j],dp[k][i]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)dp[i][i]=0;
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll ans=inf;
		for(Node e:st[x]){
			for(Node z:st[y]){
				ans=min(e.d+z.d+dp[e.p][z.p],ans);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
