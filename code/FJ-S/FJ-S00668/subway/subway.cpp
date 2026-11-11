#include<bits/stdc++.h>
using namespace std;
long long floyed[505][505],w[500005];
vector<long long>e1[500005];
vector<int>e[500005];
int c,n,m,d,q,k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		int a;
		long long wei;
		for(int j=1;j<=k;j++){
			cin>>a>>wei;
			e[a].push_back(i);
			e1[a].push_back(wei);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			floyed[i][j]=500000000000001;floyed[j][i]=500000000000001;
		}
		floyed[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<e[i].size();j++){
			floyed[e[i][0]][e[i][j]]=min(floyed[e[i][0]][e[i][j]],e1[i][0]+e1[i][j]);
			floyed[e[i][j]][e[i][0]]=floyed[e[i][0]][e[i][j]];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				floyed[i][j]=min(floyed[i][k]+floyed[k][j],floyed[i][j]);
				floyed[j][i]=floyed[i][j];
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		long long ans=500000000000001;
		for(int i=0;i<e[x].size();i++){
			for(int j=0;j<e[y].size();j++){
				ans=min(floyed[e[x][i]][e[y][j]]+e1[x][i]+e1[y][j],ans);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
