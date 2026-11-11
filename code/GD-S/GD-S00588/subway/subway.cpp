#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[1005],t[505][50005];
bool a[505][50005];
/*void dij(int x,int y){
	ll used =0;
	for(int i=1;i<=m;i++){
		for(int e=1;e<=n;e++){
			for(int h=e+1;h<=n;h++){
				if(a[e][i]==a[f][i]) used =i;
			}
		}
	}
	for(int j=1;j<=n;j++){
		int minv=maxv;
		for(int i=x;i<=y;i++){
			if(w[i]<minv&&a[j][i]){
				minv=w[i];
			}
		}
		for(int z=x;z<=y;x++){
			if(a[used][z]<maxv){
				if(dist[z]>edge[used][z]+dist[used]){
					dist[z]=edge[used][z]+dist[used]
				}
			}
		}
	}
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int whe,tm;
			cin>>whe>>tm;
			a[i][whe]=false;
			t[i][whe]=tm;
		}
	}
	for(int i=1;i<=q;i++){
		ll xr,yr;
		cin>>xr>>yr;
		ll ans=w[xr]+w[yr];
		for(int j=1;j<=n;j++){
			if(a[j][xr]==a[j][yr]){
				ans+=t[j][xr]+t[j][yr];
			}
		}
		cout<<ans;
	}
	return 0;
}
