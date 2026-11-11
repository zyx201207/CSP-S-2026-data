#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10,inf=3e18;
ll c,n,m,d,q,ans,w[N],k[N],a[510][N],t[510][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		ans=inf;
		
	}
}
