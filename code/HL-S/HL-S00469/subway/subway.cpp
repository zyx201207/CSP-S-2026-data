#include<bits/stdc++.h>
using namespace std;
int a[550][400050];
int t[550][400050];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k[n+1];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int b[n+1][m+1]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			b[i][a[i][j]]=1;
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		int ti=INT_MAX;
		for(int i=1;i<=n;i++){
			if(b[i][x]==1&&b[i][y]==1){
				ti=min(ti,t[i][x]+t[i][y]+w[x]+w[y]);
			}
		}
		if(ti!=INT_MAX){
			cout<<ti;
		}
		else{
			for(int i=1;i<=n;i++){
				if(b[i][x]==1){
					for(int j=1;j<=k[i];j++){
						for(int p=1;p<=n;p++){
							if(b[p][a[i][j]]==1&&b[p][y]==1){
								ti=min(ti,w[x]+w[y]+t[i][x]+t[p][y]+t[i][a[i][j]]+t[p][a[i][j]]);
							}
						}
					}
				}
			}
			cout<<ti;
		}
	}
	return 0;
}
