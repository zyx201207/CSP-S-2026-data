#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int w[N],k[500][1005],t[500][1005];
int x,y;
struct node{
	bool f[505];
}a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i][0];
		for(int j=1;j<=k[i][0];j++){
			cin>>k[i][j];
			cin>>t[i][k[i][j]];
			a[k[i][j]].f[i]=1;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		bool f1=0;
		for(int j=1;j<=n;j++){
			if(a[x].f[j]==1&&a[y].f[j]==1){
				f1=1;
				cout<<w[x]+t[j][x]+t[j][y]+w[y]<<endl;
				break;
			}
		}
		if(f1==1) continue;
		else{
			int id;
			for(int j=1;j<=m;j++){
				bool f2=1;
				for(int k=1;k<=n;k++){
					if(a[j].f[k]==0){
						f2=0;
						break;
					}
				}
				if(f2==1){
					id=j;
					break;
				}
			}int j1,j2;
			for(int j=1;j<=n;j++){
				if(a[x].f[j]==1){
					 j1=j;
					 
				}
				if(a[y].f[j]==1) { 
					 j2=j; 
				}
			}
			cout<<endl<<w[x]+t[j1][x]+t[j1][id]+t[j2][id]+t[j2][y]+w[y];
		}
	}
	return 0;
}
