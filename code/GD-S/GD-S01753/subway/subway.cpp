#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,q,d,ans;
	cin>>c>>n>>m>>d>>q;
	long long a[m+1],k[n+1],g[n][m];
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>g[i][j];
		}
	}
	while(q--){
		long long r,l;
		cin>>r>>l;
		cout<<a[r]+a[l];
	}
}
