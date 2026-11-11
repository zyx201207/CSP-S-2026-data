#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500010],k[510],a[510][510],t[510][510],x[100010],y[100010],xy[100010];
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
			t[j][i]=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		for(int j=x[i];j<=y[i];j++){
			xy[j]+=(w[j]+t[j][j+1]);
		}
	}
	for(int i=1;i<=q;i++){
		cout<<xy[i]<<'\n';
	}
	return 0;
}
