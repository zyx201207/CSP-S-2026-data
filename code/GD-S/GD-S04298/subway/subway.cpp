#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=0x3f3f3f3f;
ll c,n,m,d,q,k,x,y,ans;
ll w[N],a[N],b[N],dd[N];
vector<pair<ll,ll>> ve[N];
void f(ll s){
	if(s==y) return;
	for(auto i:ve[s]){
		if(dd[i.second]>dd[s]+i.first){
			dd[i.second]=dd[s]+i.first;
			f(i.second);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>b[a[j]];
		}
		for(int u=1;u<=k;u++){
			for(int v=u+1;v<=k;v++){
				ve[a[u]].push_back({b[a[u]]+b[a[v]],a[v]});
				ve[a[v]].push_back({b[a[u]]+b[a[v]],a[u]});
			}
		}
	}
	while(q--){
		ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		for(int i=1;i<=m;i++){
			dd[i]=M;
		}
		dd[x]=0;
		f(x);
		ans+=dd[y];
		cout<<ans<<endl;
	}
	return 0;
}
