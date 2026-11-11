#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[520000],k[520],a[520][520000],t[520][520000],x[100010],y[100010];
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
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		cout<<w[x[i]]+t[1][x[i]]+t[1][y[i]]+w[y[i]]<<"\n";
	}
	return 0;
} 
