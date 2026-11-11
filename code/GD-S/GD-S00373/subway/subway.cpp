#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=5e5+5;
ll c,n,m,d,q,w[maxn],k[505],u[100005],v[100005],dis[maxn],vis[maxn];
pair<ll,ll>a[maxn][505];
struct subp{
	vector<ll>vsd;
	ll id;
};
subp mp[maxn];
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i]*2;j++){
			cin>>a[j]->first>>a[j]->second;
			mp[a[j-1]->first].vsd.push_back(a[j]->first);
			mp[a[j]->first].vsd.push_back(a[j-1]->first);
			mp[a[j-1]->first].id=i;
			mp[a[j]->first].id=i;
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>u[i]>>v[i];
	}
	for(ll i=1;i<=q;i++){
		for(ll j=1;j<=m;j++){
			for(ll k=1;k<=m;k++){
				ll di=0;
				if(mp[j].id!=mp[k].id)di=1;
				if(dis[k]>dis[j]+di){
					dis[k]=dis[j]+di;
				}
			}
			vis[j]=1;
		}
		cout<<dis[v[i]]*(a[1]->second+1)*2+w[u[i]]+w[v[i]]<<'\n';
	}
	return 0;
}
