#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a[500010][500010],t[500010][500010],g[500010][500010];
long long k[500010],x[100010],y[100010];
long long o=0,p=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<long long> w(m);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<n;i++){
		cin>>k[i];
		for(int j=1;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[i][j]=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			k[j]=max(k[j],w[i]+t[i][j]+(t[i][j+1]+t[i+1][j+1])+t[i+1][i+2]+w[i+2]);
		}
		cout<<k[n]<<"\n";
		for(int j=1;j<=n;j++){
			k[j]=max(k[j],w[i]+t[i][j]+t[i][j+1]+w[i+1]);
		}
		cout<<k[n];
		break;
	}
	return 0;
}
