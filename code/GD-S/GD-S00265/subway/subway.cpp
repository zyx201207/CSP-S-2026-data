#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=5e5+510;
int c,n,m,d,q;
struct node{
	int d,p;//dis point
};
int w[maxn];
//vector<vector<node> > a(maxn);
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	
	if(c>=1&&c<=6){
		//small
		int nm=n+m;
		int aa[405][405];
		for(int i=1;i<=355;i++){
			for(int j=1;j<=355;j++){
				aa[i][j]=1e12;
			}
		}
		for(int i=1;i<=355;i++) aa[i][i]=0;
		for(int i=1;i<=n;i++){
			int kk;
			cin>>kk;
			for(int j=1;j<=kk;j++){
				int u,t;
				cin>>u>>t;
				aa[u][i+m]=t;
				aa[i+m][u]=t;
			}
		}
		for(int i=1;i<=nm;i++){
			for(int j=1;j<=nm;j++){
				for(int k=1;k<=nm;k++){
					aa[j][k]=min(aa[j][k],aa[j][i]+aa[i][k]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			int l,r;
			cin>>l>>r;
			cout<<w[l]+w[r]+aa[l][r]<<'\n';
		}
		return 0;
	}
	
	
	if(c>=7&&c<=11){
		//A
		int aa[m+10][m+10];
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++) aa[i][j]=1e12;
		}
		
		for(int i=1;i<=m;i++) aa[i][i]=0;
		for(int i=1;i<=n;i++){
			int kk;
			cin>>kk;
			if(kk==1){
				cin>>kk>>kk;
			}
			if(kk==2){
				int u,v,t1,t2;
				cin>>u>>t1>>v>>t2;
				aa[u][v]=t1+t2;
				aa[v][u]=t1+t2;
			}
		}//sum_point=m+n 
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=m;k++){
					aa[j][k]=min(aa[j][k],aa[j][i]+aa[i][k]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			int l,r;
			cin>>l>>r;
			cout<<w[l]+w[r]+aa[l][r]<<'\n';
		}
		return 0;
	}
	
	
	
	
		int nm=n+m;
		int aa[nm+10][nm+10];
		for(int i=1;i<=nm;i++){
			for(int j=1;j<=nm;j++){
				aa[i][j]=1e12;
			}
		}
		for(int i=1;i<=nm;i++) aa[i][i]=0;
		for(int i=1;i<=n;i++){
			int kk;
			cin>>kk;
			for(int j=1;j<=kk;j++){
				int u,t;
				cin>>u>>t;
				aa[u][i+m]=t;
				aa[i+m][u]=t;
			}
		}
		for(int i=1;i<=nm;i++){
			for(int j=1;j<=nm;j++){
				for(int k=1;k<=nm;k++){
					aa[j][k]=min(aa[j][k],aa[j][i]+aa[i][k]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			int l,r;
			cin>>l>>r;
			cout<<w[l]+w[r]+aa[l][r]<<'\n';
		}
		return 0;
	
	return 0;
}
/*
c=[0,25]
n=500
m=sum_ki=5e5
d=20
q=1e5
w=1e9
ki<=m
ai,j<=m ti,j<=1e9

*/
 
