#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
long long dis[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			dis[m+i][a]=t;
			dis[a][m+i]=t; 
		}
	}
	for(int i=1;i<=n+m;i++){
		dis[i][i]=0;
	}
	for(int l=1;l<=n+m;l++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				for(int k=1;k<=n+m;k++){
//					cout<<i<<" "<<j<<" "<<k<<endl;
//					cout<<dis[i][j]<<" "<<dis[j][k]<<" "<<dis[i][k]<<endl;
					if(dis[i][j]+dis[j][k]<dis[i][k]){
						dis[i][k]=dis[i][j]+dis[j][k];
					}
				}
			}
		}
	}
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+dis[x][y]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
