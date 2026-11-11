#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[500005]; 
ll x[500005],y[500005];
ll a[500005],t[500005];
ll k[505];
void bfs(ll ak,ll b,ll c){
	if(ak==b){
		cout<<c<<"\n";
		return;
	}
	for(ll i=1;i<=n;i++){
		bool zhao=0;ll o=0;
		for(ll j=1;j<=k[i];j++){
			if(ak==a[j]){
				zhao=1;
				o=j;
			}
			if(zhao==1){
				c+=t[o]+w[ak];
				bfs(a[j],b,c);
				c-=t[o]+w[ak];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		bfs(x[i],y[i],0);
	}
	return 0;
}
