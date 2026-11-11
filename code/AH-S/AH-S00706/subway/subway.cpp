#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],vis[500005],dis[500005],sum[505];
struct node{
	int num,s;
	bool operator < (const node &x) const{
		return x.s<s;
	}
};
vector<int>a[505],t[505];
vector<node>v[500005],mp[500005];
int dijkstra(int j,int x,int s,int ed){
	priority_queue<node>q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push((node){
		s,0
	});
	while(!q.empty()){
		node n1=q.top();
		q.pop();
		if(vis[n1.num])continue;
		vis[n1.num]=1;
		for(int i=0;i<int(v[n1.num].size());i++){
			int to=v[n1.num][i].num,c=v[n1.num][i].s;
			if(dis[to]>dis[n1.num]+c){
				dis[to]=dis[n1.num]+c;
				q.push((node){
					to,dis[to]
				});
			}
		}
	}
	int ans=1e9;
	for(int i=1;i<=n;i++){
		int l=0,r=0;
		for(int jj=1;jj<=k[i];jj++){
			if(a[j][jj]==x){
				l=jj;
				break;
			}
		}
		for(int jj=1;jj<=k[i];jj++){
			if(a[i][jj]==ed){
				r=jj;
				break;
			}
		}
		if(!l&&!r)continue;
		ans=min(ans,dis[(i-1)*m+ed]+t[j][l]+t[i][r]);
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=m;i++)a[i].push_back(0),t[i].push_back(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
			mp[a[i][j]].push_back((node){
				i,t[i][j]
			});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<int(mp[i].size());j++){
			for(int kk=j+1;kk<int(mp[i].size());kk++){
				int l=mp[i][j].num,r=mp[i][kk].num;
				v[i+m*(l-1)].push_back((node){
					i+m*(r-1),mp[i][j].s+mp[i][kk].s
				});
				v[i+m*(r-1)].push_back((node){
					i+m*(l-1),mp[i][j].s+mp[i][kk].s
				});
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			v[a[i][j]+m*(i-1)].push_back((node){
				a[i][j+1]+m*(i-1),0
			});
			v[a[i][j+1]+m*(i-1)].push_back((node){
				a[i][j]+m*(i-1),0
			});
		}
	}
	int ans;
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ans=1e9;
		for(int j=1;j<=n;j++){
			ans=min(ans,dijkstra(j,x,x+(j-1)*m,y)+w[x]+w[y]);
		}
		printf("%d\n",ans);
	}
	return 0;
} 
