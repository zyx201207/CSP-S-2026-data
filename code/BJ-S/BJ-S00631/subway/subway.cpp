#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,w[500005],a[505][500005],t[505][500005],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		long long sum=0;
		sum+=w[x[i]]+t[x[i]][y[i]]+t[x[i]][y[i]]+w[y[i]];
		cout<<sum<<endl;
	}
	
	return 0;
}
