#include<bits/stdc++.h>
using namespace std;
int c;
int n,m,d,q;
int w[500005];
int k[505];
int dis[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int x,y,u,v;
		cin>>k[i];
		cin>>x>>y>>u>>v;
		dis[x][u]=y+v;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}

