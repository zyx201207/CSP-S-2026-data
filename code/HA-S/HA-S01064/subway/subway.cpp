#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
int c,n,m,d,q,w[50005],k[505],x[10005],y[10005],a[505][20005],dis[505][20005];
ll ans,cnt=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dis,0x3f3f3f3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//站口到站厅距离
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];//第i条线路经过站点数量
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];//第i条线路经过站点编号
			cin>>dis[a[i][j]][j];//该站台到该线路的距离 
			dis[a[i][j]][j]=dis[j][a[i][j]];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int kk=1;
		ans=ans+w[x[kk]]+w[y[kk]];
		cout<<ans+dis[x[kk]][y[kk]];
		ans=0;
		kk++;
		cout<<'\n';
	}
	return 0;
}
