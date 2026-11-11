#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,K=5010;
ll c,n,m,d,qu,ans,p,q,k;
ll w[K],a[K],t[K],dis[K][K];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[j]>>t[j];
		for(int x=1;x<=k;x++)
			for(int y=x+1;y<=k;y++){
				int l=a[x],r=a[y],tt=t[x]+t[y];
				dis[l][r]=dis[r][l]=tt;
			}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(qu--){
		cin>>p>>q;
		cout<<w[p]+w[q]+dis[p][q]<<endl;
	}
	return 0;
}
