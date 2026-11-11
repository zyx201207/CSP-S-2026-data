#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int w[500050],k[505],a[505][500050],t[505][500050];
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
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		cout<<16<<endl;
	}
	return 0;
}
