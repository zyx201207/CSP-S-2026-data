#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],a[505][N],k[505],t[505][N],aa[505][N];
vector<int>dd[N];
vector<pii>v[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			aa[i][a[i][j]]=t[i][j];
			dd[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<dd[i].size()-1;j++){
			for(int k=j+1;k<dd[i].size();k++){
				v[dd[i][j]].push_back({aa[i][dd[i][j]]+aa[i][dd[i][k]],dd[i][k]});
				v[dd[i][k]].push_back({aa[i][dd[i][j]]+aa[i][dd[i][k]],dd[i][j]});
			}
		}
	}
	if(c<=8){
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			priority_queue<pii,vector<pii>,greater<pii> >q;
			int dis[505]={};
			bool vis[505]={};
			memset(dis,0x3f,sizeof(dis));
			for(int i=1;i<=n;i++){
				if(aa[i][x]){
					q.push({w[x],i});
					dis[i]=w[x];
				}
			}
			while(!q.empty()){
				int x=q.top().second;
				q.pop();
				if(aa[x][y])break;
				if(vis[x])continue;
				vis[x]=1;
				for(auto j:v[x]){
					int d=j.first,y=j.second;
					if(dis[y]>dis[x]+d){
						dis[y]=dis[x]+d;
						q.push({dis[y],y});
					}
				}
			}
			cout<<dis[y]<<endl;
		}
	}
	return 0;
}
