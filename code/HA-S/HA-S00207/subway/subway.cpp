#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10010;
int c,m,n,d,Q,a[maxn],dt[2][maxn],x,y;
ll g[maxn][maxn];
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>c>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=69540876599103;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,t;i<=m;i++){
		cin>>t;
		for(int j=1;j<=t;j++){
			cin>>x>>y;
			dt[0][j]=x;
			dt[1][j]=y;
		}
		for(int j=1;j<=t;j++){
			for(int k=j+1;k<=t;k++){
				g[dt[0][j]][dt[0][k]]=min(g[dt[0][j]][dt[0][k]],(ll)dt[1][j]+dt[1][k]);
				g[dt[0][k]][dt[0][j]]=g[dt[0][j]][dt[0][k]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i+1;k<j;k++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(Q--){
		cin>>x>>y;
		if(x>y){
			int k=x;
			x=y;
			y=k;
		}
		cout<<g[x][y]+a[x]+a[y]<<'\n';
	}
	
	return 0;
}