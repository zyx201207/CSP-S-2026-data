#include <bits/stdc++.h>
using namespace std;
int dots[2000][2000]={100};
int w[500]={0};
int k[500]={0};
int a[500][1000]={0};
int t[500][1000]={0};
int x[100000]={0};
int y[100000]={0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dots,1,sizeof(dots));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<=m;i++){
		dots[i][i]=0;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<k[i];j++){
			for(int l=0;l<k[i];l++){
				dots[a[i][j]][a[i][l]]=min(t[i][j]+t[i][l],dots[a[i][j]][a[i][l]]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int l=0;l<m;l++){
				if(j==l){
					continue;
				}
				for(int o=0;o<m;o++){
					dots[j][l]=min(dots[j][l],dots[j][o]+dots[o][l]);
				}
			}
		}
	}
	cout<<w[x[0]-1]+w[y[0]-1]+dots[x[0]][y[0]];
	for(int i=1;i<q;i++){
		int t=w[x[i]-1]+w[y[i]-1]+dots[x[i]][y[i]];
		cout<<endl<<t;
	}
	return 0;
} 
