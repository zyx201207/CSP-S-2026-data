#include<bits/stdc++.h>
using namespace std;
long long w[5005];
long long dis[1010];
long long vis[1010][1010];
int e[1010][1010];
void dij(int x){
	for(int i=1;i<=1010;i++){
		if(vis[x][i]==1){
			if(dis[i]>dis[x]+e[i][x]){
				dis[i]=dis[x]+e[i][x];
				//cout<<dis[i]<<endl;
				//cout<<x<<" "<<i<<endl;
				dij(i);
			}
		}
	
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k=1;
	for(int i=1;i<=n;i++){
		int h;
		cin>>h;
		for(int j=1;j<=h;j++){
			int x,y;
			cin>>x>>y;
			e[x][m+k]=y;
			e[m+k][x]=y;
			vis[x][m+k]=1;
			vis[m+k][x]=1;
		}
		k++;
	}
	for(int i=1;i<=q;i++){
		for(int i=1;i<=m+k-1;i++){
			dis[i]=1e18;
		}
		int x,y;
		cin>>x>>y;
		dis[x]=0;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
