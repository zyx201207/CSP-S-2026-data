#include <bits/stdc++.h>
using namespace std;
int dis[10005][10005];
int w[10005];
int v[10005];
struct node{
	int l,to;
};
int c,n,m,d,r;
vector <node> b[10005];
vector <node> a[10005];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > dl;
void dfs(int start){
	dis[start][start]=0;
	dl.push(make_pair(0,start));
	
	while(!dl.empty()){
		int bh=dl.top().second;
		dl.pop();
		if(v[bh])continue;
		v[bh]=1;
	
		for(int i=0;i<a[bh].size();i++){
			for(int j=0;j<b[a[bh][i].to].size();j++){
				int k=b[a[bh][i].to][j].to;
				
				if(dis[start][k]>dis[start][bh]+a[bh][i].l+b[a[bh][i].to][j].l){
					dis[start][k]=dis[start][bh]+a[bh][i].l+b[a[bh][i].to][j].l;
					if(!v[k]){
						dl.push(make_pair(dis[start][k],k));
					}
				
				}
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			node q;
			cin>>q.to>>q.l;
			b[i].push_back(q);
			int p=q.to;
			q.to=i;
			a[p].push_back(q);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		while(!dl.empty())dl.pop();
		
		memset(v,0,sizeof(v));
		dfs(i);
	}
	while(r--){
		int y,u;
		cin>>y>>u;
		cout<<w[y]+w[u]+dis[y][u]<<endl;
	}
	return 0;
} 
