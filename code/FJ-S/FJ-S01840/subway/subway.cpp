#include<bits/stdc++.h>
using namespace std;
const int M=5e3+1;
long long mapp[M][M]={};
long long c,n,m,d,q;
void deb(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<mapp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	long long w[M]={},a[501][M][2]={};
	for(int i=1;i<=m;i++){
		cin>>w[i];mapp[i][0]=5e5+1;
		for(int j=1;j<=m;j++){
			mapp[i][j]=5e5+1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][0][0];
		for(int j=1;j<=a[i][0][0];j++){
			cin>>a[i][j][0]>>a[i][j][1];
		}
		for(int j=1;j<=a[i][0][0];j++){
			for(int k=j+1;k<=a[i][0][0];k++){
				mapp[a[i][j][0]][a[i][k][0]]=min(mapp[a[i][j][0]][a[i][k][0]],a[i][j][1]+a[i][k][1]);
				mapp[a[i][k][0]][a[i][j][0]]=mapp[a[i][j][0]][a[i][k][0]];
			}
		}
	}
	bool e[M]={};
	while(q--){
		int x,y;
		cin>>x>>y;
		if(e[x]==0){
			e[x]=1;
			bool b[M]={};
			for(int i=1;i<=m;i++){
				int minn=0;
				for(int j=1;j<=m;j++){
					if(mapp[x][minn]>mapp[x][j]&&j!=x&&b[j]==0){
						minn=j;
					}
				}
				b[minn]=1;
				for(int j=1;j<=m;j++){
					if(j!=x){
						mapp[x][j]=min(mapp[x][j],mapp[x][minn]+mapp[minn][j]);
						mapp[j][x]=mapp[x][j];
					}
				}
			}	
		}
		cout<<mapp[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}

