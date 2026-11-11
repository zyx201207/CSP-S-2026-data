#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
struct node{
	int x,w;
};
int n,m,c,d,q,w[N],dis[505][505];
vector<node>a[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		int x,y,z;cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y>>z;
			a[y].emplace_back(node{i,z});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)	dis[i][j]=1e18;
	for(int i=1;i<=m;i++)
		for(int j=0;j<a[i].size();j++)
			for(int k=j+1;k<a[i].size();k++){
				dis[a[i][j].x][a[i][k].x]=min(dis[a[i][j].x][a[i][k].x],a[i][j].w+a[i][k].w);
				dis[a[i][k].x][a[i][j].x]=min(dis[a[i][k].x][a[i][j].x],a[i][j].w+a[i][k].w);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(node u:a[x])
			for(node v:a[y])
				ans=min(ans,dis[u.x][v.x]+u.w+v.w+w[x]+w[y]);
		cout<<ans<<"\n";
	}
	return 0;
}
