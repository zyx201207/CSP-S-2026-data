#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[500005][500005],t[500005][500005],x,y,k[500005],ans;
long long g;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j][k[i]];
			cin>>t[j][k[i]];
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+t[1][x]+t[1][y];
	}
	return 0;
}
