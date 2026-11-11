#include<bits/stdc++.h>
using namespace std;
//const int M=2e5+5;
//const int N=2e4+5;
int c,n,m,d,q,k,x,y;
//int dis[N][N];
long long a,t;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	long long s=m+n,w[m+5];
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
//		cout<<333<<endl;
	}
//	long long dis[s+1][s+1];
//	cout<<111<<endl;
	long long f[s+1][s+1];
//	cout<<222<<endl;
//	dis[0][0]=100;
	for(int i=1;i<=s;i++){
		for(int j=1;j<=s;j++){
			f[i][j]=-1;
		}
		f[i][i]=0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			f[a][m+i]=t;
			f[m+i][a]=t;
//			cout<<444<<endl;
		}
	}
	
	for(int k=1;k<=s;k++){
		for(int i=1;i<=s;i++){
			for(int j=1;j<=s;j++){
				if(f[i][k]<0||f[k][j]<0){
					continue;
				}
				if(f[i][j]<0){
					f[i][j]=f[i][k]+f[k][j];
				}
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//				cout<<555<<endl;
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>x>>y;
//		cout<<666<<endl;
		cout<<f[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}

