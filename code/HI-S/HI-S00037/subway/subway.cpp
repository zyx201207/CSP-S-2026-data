#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a[505][505],t[505][505],x[500005],y[500005];
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
	long long sum=0; 
	for(int j=1;j<=q;j++){
		for(int i=x[j];i<=y[j];i++){
			sum=sum+w[i]+t[1][i];
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
