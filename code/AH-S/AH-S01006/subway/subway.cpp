#include<iostream>
using namespace std;
long long c,n,m,d,q,w[500010];
long long dis[1010][1010];
void fl(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
		dis[i][j]=0x3f3f3f3f;
	}
	for(int i=1;i<=n;i++){
		long long k,a[1010],t[1010];
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
		for(int o=1;o<k;o++)
			for(int p=o+1;p<=k;p++)
				dis[a[o]][a[p]]=min(dis[a[o]][a[p]],t[o]+t[p]),
				dis[a[p]][a[o]]=min(dis[a[p]][a[o]],t[o]+t[p]);
	}
	fl();
	for(int i=1;i<=q;i++){
		long long x,y,ans;
		cin>>x>>y;
		ans=w[x]+w[y]+dis[x][y];
		cout<<ans<<'\n';
	}
	return 0;
}
