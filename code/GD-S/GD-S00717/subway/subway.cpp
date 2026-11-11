#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,NN=1e5+5;
long long c,n,m,d,q,w[N],k[N],a[N][N],t[N][N],x[NN],y[NN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>x[r]>>y[r];
	}
	
}
