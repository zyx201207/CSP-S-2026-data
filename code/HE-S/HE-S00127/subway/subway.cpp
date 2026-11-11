#include <bits/stdc++.h>
using namespace std;
constexpr int N=5009,M=5e5+7;
int c,n,m,d,q;
int w[M];
int k[N],a[M],t[M];
int f[N][N];
int32_t main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k[i];j++){
			for(int k1=1;k1<=k[i];k1++){
				if(j==k1) continue;
				f[a[j]][a[k1]]=t[j]+t[k1];
			}
		}		
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k1=1;k1<=m;k1++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j) continue;
				f[i][j]=min(f[i][j],f[i][k1]+f[k1][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+f[x][y]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
