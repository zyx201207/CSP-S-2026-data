#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q,w[500005],a[505][500005],t[505][500005],x,y;
int c;
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
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){ 
		cin>>x>>y;
		cout<<w[x]+w[y]+2*t[1][1]<<endl;
	}
	return 0;
} 
