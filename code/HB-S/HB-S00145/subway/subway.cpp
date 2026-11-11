#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],a[10005][10005],t[10005][10005],dd[10005][10005];
int main(){
	memset(dd,63,sizeof(dd));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i],dd[i][i]=0;
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			for(int jj=1,v,u;jj<j;jj++){
				v=a[i][jj],u=a[i][j];
				dd[u][v]=min(dd[u][v],t[i][j]+t[i][jj]);
				dd[v][u]=min(dd[v][u],t[i][j]+t[i][jj]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]);
			}
		}
	}
	//for(int i=1;i<=m;i++){for(int j=1;j<=m;j++)cout<<dd[i][j]<<" ";cout<<endl;}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;//cout<<w[x]<<" "<<w[y]<<endl;
		cout<<w[x]+w[y]+dd[x][y]<<endl;;
	}
	return 0;
}
