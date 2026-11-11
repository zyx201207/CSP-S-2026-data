#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1000;
struct h{
	int x,val;
	bool operator<(const h& a)const{
		return val>a.val;
	}	
};
int c,n,m,d,qu;
int w[N],dis[510][510];
vector<h>v[N];
vector<int>vs,ds,em(N,0);
priority_queue<h>q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[i+m].push_back({a,t});
			v[a].push_back({i+m,t});
		}
	}
	for(int i=1;i<=n;i++){
		q.push({i+m,0});
		ds=vs=em;
		while(!q.empty()){
			int x=q.top().x;
			int val=q.top().val;
			q.pop();
			if(vs[x])continue;
			vs[x]=1;
			ds[x]=val;
			for(int i=0;i<v[x].size();i++){
				q.push({v[x][i].x,v[x][i].val+ds[x]});
			}
		}
		for(int j=1;j<=n;j++){
			dis[i][j]=ds[j+m];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&j!=k&&i!=k)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(qu--){
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				int t1=v[x][i].x-m;
				int t2=v[y][j].x-m;
				int t=dis[t1][t2]+v[x][i].val+v[y][j].val+w[x]+w[y];
				ans=min(ans,t); 
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
