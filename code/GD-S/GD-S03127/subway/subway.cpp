#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q,k[505],x[100005],y[100005],a[505][100005],t[505][100005],t1[8005][8005];
ll w[500005];
bool b[505][500005],vis[500005];
vector<int> v[500005];
int bfs(int x,int y,ll sum){
	if(x==y) return sum;
	queue<int> q;
	q.push(x);
    memset(vis,0,sizeof(vis));
	vis[x]=1;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=0;i<v[t].size();i++){
			if(vis[v[t][i]]==0&&v[t][i]>0){
				bool flag=false;
				for(int j=1;i<=n;j++){
					if(b[j][x]==1&&b[j][v[t][i]]==1){
						flag=true;
						break;
					}
				}
				if(flag) return bfs(v[t][i],y,sum+2*t1[x][v[t][i]]);
				else  return bfs(v[t][i],y,sum);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//每个地铁站的地铁口走到站厅需要的时间
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];//每条路线经过的地铁站数量 
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];//第i条路线经过第j个地铁站 
			b[i][a[i][j]]=1;
			int s=a[i][j-1],e=a[i][j];
			t1[s][e]=t[i][j];
			v[s].push_back(e);
			v[e].push_back(s);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	} 
	for(int i=1;i<=q;i++){
		ll ans=0;
		ans+=(w[x[i]]+w[y[i]]);
		cout<<ans<<endl;	
	}
	return 0;
}
