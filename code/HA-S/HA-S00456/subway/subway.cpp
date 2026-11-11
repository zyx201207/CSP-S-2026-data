#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int a[N][N],n,m,c,d,q,t[N][N],dis[N][N],w[N],k[N];
vector<pair<int,int>>e[N];
void fl(){
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			
		}	
		for(int j=1;j<=k[i];j++)
			for(int l=j+1;l<=k[i];l++){
				e[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
				dis[a[i][j]][a[i][l]]=t[i][j]+t[i][l];
				dis[a[i][l]][a[i][j]]=t[i][j]+t[i][l];
			}
	}
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	fl();
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
}