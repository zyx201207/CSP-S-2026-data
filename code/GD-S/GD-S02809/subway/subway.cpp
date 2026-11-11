#include<bits/stdc++.h>
using namespace std;
int c,n,m,di,q,x,y,w[20001];
int kk[1001],a[20001],t[20001];
int d[20001][20001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>di>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>kk[i];
		for(int j=1;j<=kk[i];j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<kk[i];j++){
			for(int k=1;j+k<=kk[i];k++){
				if(d[a[j]][a[j+k]]!=0){
					d[a[j]][a[j+k]]=min(d[a[j]][a[j+k]],t[j]+t[j+k]);
				}
				else d[a[j]][a[j+k]]=t[j]+t[j+k];
				d[a[j+k]][a[j]]=d[a[j]][a[j+k]];
			}
		}
	}
	
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(d[i][k]==0) continue;
			for(int j=i+1;j<=m;j++){
				if(d[k][j]==0) continue;
				if(d[i][j]!=0) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				else d[i][j]=d[i][k]+d[k][j];
				d[j][i]=d[i][j];
			}
		}
	}
	
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+d[x][y]<<endl; 
	}
	return 0;
}
