#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500005;
ll c,n,m,d,q;
ll w[N],k[N];
ll a[4][N],b[4][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>b[i][a[i][j]];
//			cout<<i<<" "<<a[i][j]<<" "<<b[i][a[i][j]]<<'\n';
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(n==1){
			int ans=0;
			ans=w[x]+b[1][x]+b[1][y]+w[y];
//			cout<<w[x]<<" "<<b[1][1]<<" "<<b[1][y]<<" "<<w[y]<<'\n';
			cout<<ans<<endl;
		}
	}
	return 0;
}
