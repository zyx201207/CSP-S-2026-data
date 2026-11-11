#include<bits/stdc++.h>
using namespace std;
const int N=501,M=5e5+1;
int c,n,m,d,q,w[M],a[N][M],t[N][M],k[N],x,y,ans[N][N],num[N][N];
void f(){
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
	}
	if(c>=9&&c<=19){
		for(int i=1;i<=n;i++)
		f();
		while(q--){
			cin>>x>>y;
			cout<<ans[x][y]+w[x]+w[y]<<'\n';
		}
	} 
	return 0;
} 
