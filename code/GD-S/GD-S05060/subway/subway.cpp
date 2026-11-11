#include<bits/stdc++.h>
using namespace std;
int w[1005];
int k[50005];
int a[105][1005];
int a1[105][1005];
int t[105][1005];
int x[1005];
int y[1005];
int x1[1005][5];
int y1[1005][5];
int z[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,t1=0,x1=0,x2=0,y1=0,y2=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i][j];
			a1[i][j]=0;
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*k[i];j++){
			if
		}
	}
	for(int t2=1;t2<=q;t2++){
		cin>>x[t2]>>y[t2];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=2*k[i];j++){
				if(a[i][j]=x[t2]){
					x1[t2][1]=i;
					x1[t2][2]=j;
				}
				if(a[i][j]=y[t2]){
					y1[t2][1]=i;
					y1[t2][2]=j;
				}
			}
		}
	}
} 
