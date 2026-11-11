#include <bits/stdc++.h>
using namespace std;
const int maxn=1001;
int c,n,m,d,q;
int w[maxn];
int a[501][maxn],t[501][maxn];
int k[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(n==1){
			cout<<w[x]+t[1][x]+t[1][y]+w[y]<<endl;
		}else{
			int ans=0;
			for(int i=1;i<=m;i++) ans+=w[i];
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i];j++) ans+=t[i][j];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
