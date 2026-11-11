#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct point{
	int x,y;
}t[500005];
int a[5000][5000];
int w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(a,-1,sizeof(a));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>t[j].x>>t[j].y;
		}
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				if(a[t[j].x][t[l].x]==-1){
					a[t[j].x][t[l].x]=t[j].y+t[l].y;
					a[t[l].x][t[j].x]=t[j].y+t[l].y;
				}else{
					a[t[j].x][t[l].x]=min(a[t[j].x][t[l].x],t[j].y+t[l].y);
					a[t[l].x][t[j].x]=a[t[j].x][t[l].x];
				}
				
			}
		}
	}
	
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(a[i][k]==-1){
				continue;
			}
			for(int j=1;j<=m;j++){
				if(a[j][k]==-1){
					continue;
				}
				if(a[i][j]==-1){
					a[i][j]=a[i][k]+a[k][j];
					a[j][i]=a[i][j];
					continue;
				}
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				a[j][i]=a[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		cout<<w[l]+w[r]+a[l][r]<<endl;
	}
	return 0;
}
