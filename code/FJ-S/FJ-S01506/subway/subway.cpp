#include<bits/stdc++.h> 
using namespace std;
int w[3000],a[3000][3000],p[3000],p2[3000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>p[j]>>p2[j];
		if(k==1) continue;
		for(int j=1;j<=k;j++){
			int x=p[j];
			int y=p2[j];
			for(int kk=j+1;kk<=k;kk++){
				a[x][p[kk]]=y+p2[kk];
				a[p[kk]][x]=y+p2[kk];
			}	
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(a[i][k]==0x3f3f3f3f) continue; 
			for(int j=1;j<=m;j++){
				if(a[k][j]==0x3f3f3f3f) continue;
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+a[x][y]+w[y]<<'\n';
	}
	return 0;
}



