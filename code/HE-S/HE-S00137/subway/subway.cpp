#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5,Q=1e5+5;
int c,n,m,d,q;
int w[M],k[N],x[Q],y[Q];
map<int,map<int,int> >a,t;
map<int,map<int,int> > G,ans;
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
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int jj=j+1;jj<=k[i];jj++){
				G[a[i][j]][a[i][jj]]=(t[i][j]+t[i][jj]);
				G[a[i][jj]][a[i][j]]=(t[i][j]+t[i][jj]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		for(int k=1;i<=n;k++){
			for(int ii=1;ii<=n;ii++){
				for(int j=1;j<=n;j++){
					if(G[ii][k]&&G[j][k]){
						ans[ii][j]=min(ans[ii][j],G[ii][k]+G[j][k]);
					}
				}
			}
		}
		cout<<ans[x[i]][y[i]]+w[x[i]]+w[y[i]];
	}
	return 0;
}
