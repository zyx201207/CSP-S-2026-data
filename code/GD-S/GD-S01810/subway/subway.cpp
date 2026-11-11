#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int dis[5005][5005],w[500005],a[500005],t[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		cin>>w[i];
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int f=1;f<j;f++){
				dis[a[f]][a[j]]=dis[a[j]][a[f]]=min(dis[a[f]][a[j]],t[f]+t[j]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<endl;
	}
	return 0;
}
