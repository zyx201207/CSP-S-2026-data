#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,p,w[1005],k[505],a[505][1005],t[505][1005],dis[1505][1505];
int to[2005],val[2005],nxt[2005],h[1505],cnt,bj[1505][1505];
void add(int u,int v,int w){
	to[++cnt]=v;
	val[cnt]=w;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
priority_queue<pair<int,int> >q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			if(i==j){
				continue;
			}
			dis[i][j]=0x3ffffffff;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			add(a[i][j],m+i,t[i][j]);
			add(m+i,a[i][j],t[i][j]);
		}
	}
	for(int j=1;j<=m+n;j++){
		dis[j][j]=0;
		q.push(make_pair(0,j));
		while(!q.empty()){
			int kk=q.top().second;
			q.pop();
			if(bj[j][kk]==1){
				continue;
			}
			bj[j][kk]=1;
			for(int i=h[kk];i;i=nxt[i]){
				int v=to[i];
				if(dis[j][v]>dis[j][kk]+val[i]){
					dis[j][v]=dis[j][kk]+val[i];
					q.push(make_pair(-dis[j][v],v));
				}
			}
		}
	}
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
} 
