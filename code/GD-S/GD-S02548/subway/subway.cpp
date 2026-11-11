#include <bits/stdc++.h>
using namespace std;
const int maxn=67,maxm=327;
struct node{
	int v,w;
};
int ceshi,n,m,maxd,q,timed[maxn],d[maxn];
vector<node>g[maxn];
vector<int>ans;
void dfs(int x,int sum,int end){
	if(sum>=d[x]){
		return;
	}
	d[x]=sum;
	if(x==end){
		return;
	}
	for(int i=0;i<g[x].size();i++){
		int tx=g[x][i].v,tw=g[x][i].w;
		dfs(tx,sum+tw,end);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ceshi>>m>>n>>maxd>>q;
	int nnnnn=n;
	int mmmmm=m;
	for(int i=1;i<=n;i++){
		n=nnnnn;
		cin>>timed[i];
	}
	for(int i=1;i<=m;i++){
		m=mmmmm;
		int x=0;
		vector<pair<int,int> >px={};
		cin>>x;
		for(int j=1;j<=x;j++){
			int xx=0,yy=0;
			cin>>xx>>yy;
			px.push_back({xx,yy});
		}
		for(int j=0;j<x;j++){
			for(int k=0;k<x;k++){
				if(j==k){
					continue;
				}
				g[px[j].first].push_back({px[k].first,px[k].second+px[j].second});
			}
		}
	}
	while(q--){
		int s=0,e=0;
		cin>>s>>e;
		d[s]=0;
		memset(d,0x3f,sizeof d);
		dfs(s,timed[s],e);
		d[e]+=timed[e];
		ans.push_back(d[e]);
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
