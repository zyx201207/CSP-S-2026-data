#include<bits/stdc++.h> 
using namespace std;
const int N=5*1e5+10;
int c,n,m,d,q,ans=0x3fffffff;
int s,f;
int w[N];
int v[N][510];//第i个地铁站的站厅到j号线的步行时间 
vector<int> g1[N];//第i个地铁站在的线路
vector<int> g2[510];//第i条线路经过的站
int vis[N];
void dfs(int now,int time,int line){
	if (now == f){
		ans=min(ans,time);
		return;
	}	
	for (int i=0;i<g1[now].size();i++){
		for (int j:g2[g1[now][i]]){
			if (vis[j] == 0 && (j == f || g1[j].size()>1)){
				if (i == 0){
					dfs(j,time,line);
					
				}
				else {
					dfs(j,time+v[j][line]+v[j][g1[now][i]],g1[now][i]);
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=2*k;j++){
			int a,t;
			cin>>a>>t;
			v[a][i]=t; 
			g2[i].push_back(a);
			g1[a].push_back(i);
		}
	}
	while (q--){
		ans=0x3fffffff;
		cin>>s>>f;
		dfs(s,0,g1[s][0]);
		cout<<ans+w[s]+w[f]<<endl;
	}
	return 0;
}
