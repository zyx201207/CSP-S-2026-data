#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[505],a[505][505],t[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
	while(q--){		
		int x,y;
		cin>>x>>y;
		ans+=w[x]+w[y];
		for(int i=x;i<y;i++){
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
