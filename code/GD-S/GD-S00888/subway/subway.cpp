#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=5e5+5;
void solve();
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	solve();
	return 0;
} 
int n,m,d,q,zt_zt[501][100001];
int k_zt[N];
vector<int> v_to[N],to_v[N];
vector<bool> vis_x(N,0);

struct data{
	int x;
	int step;
	int line;
}; 
 
void solve(){
	cin>>n>>m>>d>>q; 
	memset(zt_zt,0,sizeof zt_zt);
	for(int i=1;i<=m;i++)
		cin>>k_zt[i],to_v[i].clear();
	for(int i=1;i<=n;i++){
		v_to[i].clear();
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
			zt_zt[i][a]=b;
			v_to[i].push_back(a);
			to_v[a].push_back(i); 
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
//		cout<<x<<' '<<y<<'\n';
		queue<data> q;
//			q=queue<data>();
		int ans=1e18;
		for(int j=0;j<to_v[x].size();j++){
//			vis_line.clear();
			q.push({x,zt_zt[to_v[x][j]][x],to_v[x][j]});
//			vis_x[to_v[x][j]][x]=1;
//			vis_line=1;
			vis_x=vector<bool>(N,0);
			while(!q.empty()){
				int now_x=q.front().x;
				int step=q.front().step;
				int line=q.front().line;
				if(step>=ans) break;
				q.pop();
				if(now_x==y){
//					cout<<k_zt[x]+step+k_zt[y]+zt_zt[line][y]<<'\n';
					ans=min(ans,k_zt[x]+step+k_zt[y]+zt_zt[line][y]);
					continue;
				}
				for(int k=0;k<v_to[line].size();k++){
					int new_x=v_to[line][k];
					if(vis_x[new_x]) continue;
					vis_x[new_x]=1;
					q.push({new_x,step,line});
				}
				for(int k=0;k<to_v[now_x].size();k++){
					int new_line=to_v[now_x][k];
					if(new_line==line) continue;
					q.push({now_x,step+zt_zt[line][now_x]+zt_zt[new_line][now_x],new_line});
				}
			}	
		}
		cout<<ans<<'\n';
	}
	return;
}
