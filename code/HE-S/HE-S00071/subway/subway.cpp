#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int w[55],a[105][105],t[105][105];
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=w[x]+t[1][x]+w[y]+t[1][y];
		cout<<ans<<endl;
	}
}
