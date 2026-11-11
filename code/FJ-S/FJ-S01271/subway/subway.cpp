#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];//从i站点的地铁口走到站厅需要w[i]的时间
long long ans;
int a[500][500005];//第i条地铁线路经过第j个站点a[i][j]
int t[500][500005];//从第j个站厅走到线路i的站台需要t[i][j]的时间
int k[500];//第i条线路经过k[i]个站点 

int f[500005];//有f[i]条地铁经过站点i; 
bool v[500005];
int e[500005][505];//p[i][j]地铁线路经过站点i
struct Node{
	int st,end;
}plan[100005];//旅行计划 
void dfs(int now,int en,long long walk,int last){
	if(now==en){
		ans=min(ans,walk+t[last][now]+w[now]);
		return;
	}
	for(int i=1;i<f[now];i++){//在这个站点可以坐的线路 
		v[now]=true;
		for(int j=1;j<=k[j];j++){
			if(a[e[now][i]][j]==now){
				if(e[now][i]==last){
					if(v[a[e[now][i]][j+1]]==false) dfs(a[e[now][i]][j+1],en,walk,last);
					if(v[a[e[now][i]][j-1]]==false) dfs(a[e[now][i]][j-1],en,walk,last);
				}else{
					if(v[a[e[now][i]][j+1]]==false) dfs(a[e[now][i]][j+1],en,walk+t[e[now][i]][now],i);
					if(v[a[e[now][i]][j-1]]==false) dfs(a[e[now][i]][j-1],en,walk+t[e[now][i]][now],i);
				}
				
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) f[i]=1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			e[a[i][j]][f[a[i][j]]]=i;
			f[a[i][j]]++;
		}
	}
	for(int i=1;i<=q;i++){
		
		cin>>plan[i].st>>plan[i].end;
		dfs(plan[i].st,plan[i].end,w[plan[i].st],0);
		cout<<ans;
	} 
}
/*
这无疑是神圣的
肥美图论 
这个地铁有病吧 
旅行全流程：
地铁口>>站厅>>站台>>另一个站台>>另一个站厅>>第三个站台>>……>>最后一个站台>>最后一个站厅>>地铁口 
不管了，暴力起手 
*/
