#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int t[500005],a[500005];
int dis[16000][16000];
void floyd(){
	for(int i=1;i<=m;i++){
		for(int k=1;k<=m;k++){
			if(dis[i][k]==INT_MAX) continue;
			for(int j=1;j<=m;j++){
				if(dis[k][j]==INT_MAX) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=INT_MAX;
			if(i==j) dis[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k); 
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a[j],&t[j]);
		}
		for(int l=1;l<=k;l++){
			for(int r=l+1;r<=k;r++){
				dis[a[l]][a[r]]=min(t[l]+t[r],dis[a[l]][a[r]]);
				dis[a[r]][a[l]]=min(t[l]+t[r],dis[a[r]][a[l]]);
			}
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
