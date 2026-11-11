#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][505],t[505][505];
int qd[500005],zd[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int u=1;u<=m;u++){
		cout<<w[u];
	}
	for(int i=1;i<=n;i++){
		cout<<k[i];
	}
	for(int j=1;j<=c;j++){
		cout<<c[j];
	}
	for(int r=1;r<=qd;r++){
		cout<<qd[r];
	}
	for(int b=1;b<=zd;b++){
		cout<<zd[b];
	}
}
