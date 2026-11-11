#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int M=5e5+5;
int w[M],a[N][N],t[N][N];
int c,n,m,d,q;
long long ans=INT_MAX;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
//		if(!t[x][y]){
		long long sum=0;
		for(int j=x;j<=y;j++){
			sum+=t[x][j];
		}
		cout<<w[x]+sum+w[y]<<'\n';
		//}
//		else{
//			ans=0;
//			dfs(x,y,0);
//			cout<<w[x]+ans+w[y]<<'\n';
//		}
	}

	return 0;
}
