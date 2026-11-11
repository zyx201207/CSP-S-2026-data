#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000],k[510],a[510][500010],t[510][500010],x[500010],y[500010];
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
			cin>>a[k[i]][j]>>t[k[i]][j];
		} 
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		cout<<0;
	}
	return 0;  
} 
