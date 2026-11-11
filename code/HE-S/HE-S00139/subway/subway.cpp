#include<bits/stdc++.h>
using namespace std;
const int N=666;
const int M=5e5+5;
long long c,n,m,d,q,dis[N][N],k,u[M],v[M],w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f3f3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		cin>>w[i];
		dis[i][i]=w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u[j]>>v[j];
		}
		for(int j=1;j<k;j++){
			for(int l=j+1;l<=k;l++){
				dis[u[j]][u[l]]=v[j]+v[l];
				dis[u[l]][u[j]]=v[j]+v[l];
			}
		}
	}
	for(int l=1;l<=m;l++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j){
					continue;
				}
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
			}
		}
	}
	while(q--){
		int start,end;
		cin>>start>>end;
		cout<<dis[start][end]+w[start]+w[end]<<'\n';
	}
	return 0;
}
