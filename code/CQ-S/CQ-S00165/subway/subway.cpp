#include<bits/stdc++.h>
using namespace std;
#define int long long
//luogu id afewdgre
struct node{
	int a,t;
};
int c,n,m,d,q,w[500005],dis[505][505];
vector<node> v[505];
vector<node> tong[500005];
bool cmp(node x,node y){
	return x.a<y.a;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[i].push_back({a,t});
			tong[a].push_back({i,t});
		}
		sort(v[i].begin(),v[i].end(),cmp);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=1e12;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else{
				int id1=0,id2=0,minn=1e12;
				while(id1<v[i].size()&&id2<v[j].size()){
					if(v[i][id1].a==v[j][id2].a) minn=min(minn,v[i][id1].t+v[j][id2].t),id1++,id2++;
					else if(v[i][id1].a<v[j][id2].a) id1++;
					else id2++;
				}
				dis[i][j]=minn,dis[j][i]=minn;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<dis[i][j]<<' ';
//		cout<<'\n';
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int minn=1e12;
		for(int j=0;j<tong[x].size();j++){
			for(int k=0;k<tong[y].size();k++){
				minn=min(minn,dis[tong[x][j].a][tong[y][k].a]+tong[x][j].t+tong[y][k].t);
			}
		}
		cout<<minn+w[x]+w[y]<<'\n';
	}
}

