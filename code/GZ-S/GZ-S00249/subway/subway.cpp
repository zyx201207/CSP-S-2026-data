//贵阳市第一中 王怀威 GZ-S00249
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=9999999;
struct whwh{
	int road[25]={0},cnt=1,dis[25]={0};
	bool vis=0;
}a[500005];
int w[500005],k,ta,aa;
int node[505][505];
int main(){
	for(int i=0;i<505;i++) for(int j=0;j<505;j++) node[i][j]=999999999;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>aa>>ta;
			a[aa].dis[a[aa].cnt]=ta;
			a[aa].road[a[aa].cnt++]=i;
			if(a[aa].vis){
				for(int l=1;l<a[aa].cnt;l++){
					node[i][a[aa].road[l]]=min(node[i][a[aa].road[l]],a[aa].dis[l]+ta);
				}
			}
			else a[aa].vis=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				node[i][j]=min(node[i][j],node[i][l]+node[l][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) node[i][j]=0;
			node[i][j]=min(node[i][j],node[j][i]);
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=99999999;
		for(int i=1;i<a[x].cnt;i++){
			for(int j=1;j<a[y].cnt;j++){
				int whw=a[x].dis[i]+a[y].dis[j]+w[x]+w[y];
				ans=min(node[a[x].road[i]][a[y].road[j]]+whw,ans);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}