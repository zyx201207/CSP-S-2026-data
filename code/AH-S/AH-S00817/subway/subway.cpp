#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int w[500010];
struct node1{
	int a,t;
};
int lineN[510];
vector <node1> line[510];
struct node2{
	int line,t;
};
vector <node2> station[500010];
long long ans,he;
bool visLine[510],visSta[500010];
void dfs(int u){
	if(u==y){
		ans=min(ans,he);
		return;
	}
	if(he>ans) return;
	visSta[u]=1;
	int lineS=station[u].size();
	for(int i=0;i<lineS;i++){ //choose a line and take
		if(!visLine[station[u][i].line]){
			visLine[station[u][i].line]=1;
			he+=station[u][i].t;
			int nowLine=station[u][i].line;
			for(int j=0;j<lineN[nowLine];j++){ //choose a station on this line
				int v=line[nowLine][j].a;
				if(!visSta[v]){
					he+=line[nowLine][j].t;
					dfs(v);
					he-=line[nowLine][j].t;
					visSta[v]=0;
				}
					
			}
			he-=station[u][i].t;
			visLine[station[u][i].line]=0;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>lineN[i];
		for(int j=1;j<=lineN[i];j++){
			node1 now; node2 sta;
			cin>>now.a>>now.t;
			line[i].push_back(now);
			sta.line=i; sta.t=now.t;
			station[now.a].push_back(sta);
		}
	}
	while(q--){
		cin>>x>>y;
		ans=LLONG_MAX; he=0;
		memset(visLine,0,sizeof(visLine));
		memset(visSta,0,sizeof(visSta));
		dfs(x);
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
