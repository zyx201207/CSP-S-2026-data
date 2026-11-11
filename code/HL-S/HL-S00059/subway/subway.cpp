#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[10000005];
int k,a[500005][505],t[500005][505];
int x[100005],y[100005],xian[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>k;
		for(int j = 1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			xian[a[i][j]] = i;
		}
		
	}
	for(int i = 1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i = 1;i<=n;i++){
		cout<<w[x[i]]+t[xian[x[i]]][x[i]]+w[y[i]]+t[xian[y[i]]][y[i]]<<endl;
	}
	return 0;
}