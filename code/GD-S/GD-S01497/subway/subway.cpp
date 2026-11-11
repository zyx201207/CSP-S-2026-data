#include<bits/stdc++.h>
using namespace std;

const int maxn=520,maxm=5e5+100,maxq=1e5+100;
int c,n,m,d,q;
int a[maxn][maxm],t[maxn][maxm];
int x[maxq],y[maxq],k[maxm],w[maxm];
int main(){	
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;	
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			t[i][j]=0;
		}
	}

	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];		
	}
	if(n==2){
		int lesst=1e9+7;
		for(int i=1;i<=m;i++){
			if(t[1][m]+t[2][m]<lesst){
				lesst=t[1][m]+t[2][m];
			}
		}
		for(int i=1;i<=q;i++){
			if(t[1][x[i]]>0&&t[2][x[i]]==0){
				if(t[1][y[i]]>0&&t[2][y[i]]==0){
					cout<<w[x[i]]+w[y[i]]+t[1][x[i]]+t[2][y[i]];
				}else if(t[2][y[i]]>0&&t[1][y[i]]==0){
					cout<<w[x[i]]+w[y[i]]+t[1][x[i]]+t[2][y[i]]+lesst;
				}
			}else if(t[2][x[i]]>0&&t[1][x[i]]==0){
				if(t[1][x[i]]>0&&t[2][x[i]]==0){
					cout<<w[x[i]]+w[y[i]]+t[2][x[i]]+t[2][y[i]];
				}else if(t[2][y[i]]>0&&t[1][y[i]]==0){
					cout<<w[x[i]]+w[y[i]]+t[2][x[i]]+t[2][y[i]]+lesst;
				}
			}else{
				cout<<w[x[i]]+w[y[i]]+min(t[1][x[i]]+t[2][y[i]],min(t[2][x[i]]+t[2][y[i]],min(t[1][x[i]]+t[2][y[i]]+lesst,t[2][x[i]]+t[2][y[i]]+lesst)));
			}
			

		}
	}
	return 0;
}
