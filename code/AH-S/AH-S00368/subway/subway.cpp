#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C,n,m,d,q,w[5100],k[5100],a[5100],t[5100],dis[5100],vis[5100];
/*
*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i]>>t[i];
		}
	}
	while(q--){
		ll xr,yr;
		cin>>xr>>yr;
		//djs(xr,yr);
		cout<<w[xr]+w[yr];
	}
	return 0;
}
