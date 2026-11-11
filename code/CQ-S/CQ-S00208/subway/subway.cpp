#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
struct node{
	int v,idx,idx1;
	bool operator<(node a)const{
		return v>a.v;
	}
};
vector<int>cu[N];
unordered_map<int,int>b[N];
bool vis[N][505];
vector<pair<int,int> >tu[N];
int c,n,m,d,k,v[N],a[N],dis[N][505],ans[N][N];
void dij(int st){
	priority_queue<node>q;
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	for(int i=0;i<cu[st].size();i++){
		int t=cu[st][i];
		dis[st][t]=b[st][t];
		q.push({b[st][t],st,t});
	}
	while(!q.empty()){
		int x=q.top().idx,y=q.top().idx1;
		q.pop();
		if(vis[x][y])
			continue;
		vis[x][y]=1;
		for(int i=0;i<tu[x].size();i++){
			int t=tu[x][i].first,t1=tu[x][i].second,z=dis[x][y];
			if(y!=t1)
				z+=b[x][y]+b[x][t1];
			if(dis[t][t1]>z){
				dis[t][t1]=z;
				q.push({z,t,t1});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ans,0x3f,sizeof ans);
	cin>>c>>m>>n>>d>>k;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int i=1;i<=m;i++){
		int t,t1;
		cin>>t;
		for(int j=1;j<=t;j++){
			cin>>a[j]>>t1;
			b[a[j]][i]=t1;
			cu[a[j]].push_back(i);
		}
		for(int j=2;j<=t;j++){
			tu[a[j-1]].push_back({a[j],i});
			tu[a[j]].push_back({a[j-1],i});
		}
	}
	while(k--){
		int x,y;
		cin>>x>>y;
		if(ans[x][y]!=0x3f3f3f3f3f3f3f3f){
			cout<<ans[x][y]<<endl;
			continue;
		}
		dij(x);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans[x][i]=min(ans[x][i],v[x]+v[i]+dis[i][j]+b[i][j]);
		cout<<ans[x][y]<<endl;
	}
	return 0;
}
