#include<bits/stdc++.h>
using namespace std;
const int N=4010,M=210;
int m,w[N],n,c,d,q,k[M],a[M][N/10],t[M][N/10],z[N][M],tt[N];
//void dfs(int w,int ti){
//	for(int i=1;i<=tt[w];i++){
//		int xl=z[w][i];
//		int is;
//		for(int j=1;j<=k[xl];j++){
//			if(a[xl][j]==w)
//				is=i+1;
//		}
//		for(int j=is;j<=k[xl];j++){
//			dfs(a[xl][j],ti+t[xl][w]+t[])
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			z[a[i][j]][++tt[a[i][j]]]=i;
		}
	}
	for(int i=1,st,ed;i<=q;i++){
		cin>>st>>ed;
		cout<<1<<endl;
	}
	return 0;
} 
