#include<bits/stdc++.h>
using namespace std;
const int M=1000;
const int N=505;
int c,n,m,d,p;
vector<pair<int,int>> e[M+N];
int w[M];
int dis[N+2*M][N+2*M];
void prim(){
	for(int i=1;i<=n+2*m;i++) dis[i][i]=0;
	for(int i=n+2*m;i>=1;i--){
		for(int j=n+2*m;j>=1;j--){
			for(int k=1;k<=n+2*m;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		dis[i][i+m]=w[i];
		dis[i+m][i]=w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			dis[a+m][2*m+i]=t;
			dis[2*m+i][a+m]=t;
		}
	}
	prim();
	for(int i=1,x,y;i<=p;i++){
		cin>>x>>y;
		cout<<dis[x][y]<<endl;
	}
	return 0;
}
