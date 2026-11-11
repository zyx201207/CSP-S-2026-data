#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int w[15],a[15][15],t[15][15];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	} 
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+t[1][x]+t[1][y]<<"\n";
	}
	return 0;
}

