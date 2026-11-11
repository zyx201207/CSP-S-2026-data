#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k,a[500][500000],t[500][500000],xz,yx;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		long long x,y;
		cin>>x>>y;
		
	}
	return 0;
} 
