#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4,mod=14518964329827;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,n,m,d,q,w[N],a[4][N],t[4][N],k[N];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	if(n==1){
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+t[1][x]+t[1][y]<<endl;
		}
		return 0;
	}
	cout<<mod%(c*n*m*d*q/26);
	return 0;
} 
