#include<bits/stdc++.h>
using namespace std;
const int N=1e6+67,M=567,K=5e5+67;
int c,n,m,d,q,k[N],w[N],a[M][K],t[M][K];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int l=1;l<=k;l++){
			cin>>a[i][l]>>t[i][l];
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		cout<<w[x]+w[y]+t[x][x]+t[x][y]<<"\n";		
	}
	
	
	return 0;
} 
