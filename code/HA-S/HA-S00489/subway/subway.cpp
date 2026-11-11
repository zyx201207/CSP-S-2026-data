#include<bits/stdc++.h>
using namespace std;
const int maxx=0x3fffffff;
int c,n,m,d,q;
int w[1005][1005],tim_[1005],a[1005],t[1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tim_[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			w[i][j]=maxx;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=2;j<=k;j++){
			w[a[j-1]][a[j]]=t[j]+t[j-1];
			w[a[j]][a[j-1]]=t[j]+t[j-1];
		}
	} 
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(w[i][j]>w[i][k]+w[k][j]){
					w[i][j]=w[i][k]+w[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<tim_[x]+w[x][y]+tim_[y]<<"\n";
	}
	return 0;
}  


