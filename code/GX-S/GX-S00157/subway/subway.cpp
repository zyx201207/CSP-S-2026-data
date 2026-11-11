#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int c,n,m,d,q,k[500001],a[501][500001],w[100001],t[501][500001];
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
			cin>>a[j][i]>>t[j][i];
		}
	}
	for(int o=1;o<=q;o++){
		int x,y;
		cin>>x>>y;
		cout<<t[x][1]+t[1][y];
	}
	return 0;
}
