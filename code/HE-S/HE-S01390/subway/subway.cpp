#include<bits/stdc++.h>
using namespace std;
int c,m,w[500001],n,k[500001],a[500001][500001],t[500001][500001],d,q,x[500001],y[500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		cout<<w[x[i]]+w[y[i]]+t[x[i]][y[i]]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
