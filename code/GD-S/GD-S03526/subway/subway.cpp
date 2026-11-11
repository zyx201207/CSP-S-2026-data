#include<bits/stdc++.h>
using namespace std;
int w[500005];
int k[505];
vector<int>a[505],t[505];
vector<int>e[500005];
int dis[5005][5005];
int qx[100005],qy[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
//	cout<<1;
	int pd=1;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(t[i][j]!=t[1][1])pd=0;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qx[i]>>qy[i];
	}
//	cout<<1;
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)dis[i][j]=-1;
	for(int i=1;i<=m;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			for(int kk=j+1;kk<=k[i];kk++){
				dis[a[i][j]][a[i][kk]]=1;
				dis[a[i][kk]][a[i][j]]=1;
			}
		}
	}
	for(int kk=1;kk<=m;kk++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=max(dis[i][j],dis[i][kk]+dis[kk][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x=qx[i],y=qy[i];
		cout<<w[x]+w[y]+2*t[1][1]*dis[x][y]<<'\n';
	}
	return 0;
} 
