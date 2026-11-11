#include <bits/stdc++.h>
using namespace std;
const int N=507,M=5e5+7;
int w[M],a[N][M],t[N][M];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y;
		long long ans=0;
		bool f1=0,f2=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if(a[i][x]!=0&&f1==0) ans+=t[i][x],f1=1;
			if(a[i][y]!=0&&f2==0) ans+=t[i][y],f2=1;
			if(f1==1&&f2==1) break;
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
