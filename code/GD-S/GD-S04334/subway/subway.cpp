#include<bits/stdc++.h>
using namespace std;
const long long N=1e3+5;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,x,y,k1,a[N][N],t[N][N],w[N];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	while(q--){
			for(int i=1;i<=n;i++){
		cin>>k1;
		for(int j=1;j<=k1;j++){
			cin>>a[i][2*j-1]>>t[i][2*j-1];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
	}
	cout<<w[x]+t[x][x]+t[x][x+1]+w[y]<<endl;
	}

	return 0;
}
