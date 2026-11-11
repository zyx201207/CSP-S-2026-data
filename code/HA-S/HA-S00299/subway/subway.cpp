#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,id;
const int N=1005,M=5e5+5,D=22;
struct node{
	int v,w;
};
int w[N];
vector<node>edge[M];
map<int,int> t;
vector<int> all[N];
map<int,int> ha;
int cur[M];
int bfs(int bg,int ed){
	int ans=INT_MAX;
	for(auto s:all[bg]){
		int tot=0;
		memset(cur,0x3f,sizeof(cur));
		queue<int> q;
		q.push(s);
		cur[s]=0;
		while(1){
			int u=q.front();
			q.pop();
			if(ha[u]==ed){
				tot=cur[u]+t[u]+t[s]+w[bg]+w[ed];
//				printf("%d %d %d %d %d\n",t[s],w[bg],t[u],w[ed],cur[u]);
				break;
			}
			for(int l=0;l<edge[u].size();l++){
				node nd=edge[u][l];
				int v=nd.v,w=nd.w;
				if(cur[v]!=0x3f3f3f3f)	continue;
				q.push(v);
				cur[v]=cur[u]+w;
			}
		}
		int minn=INT_MAX;
		for(auto v:all[ed]){
			minn=min(minn,tot);
		}
		ans=min(ans,minn);
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,T;
			cin>>a>>T;
			id++;
			t[id]=T;
			all[a].push_back(id);
			ha[id]=a;
			if(j!=1){
				edge[id].push_back({id-1,0});
				edge[id-1].push_back({id,0});
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<all[i].size();j++){
			int w=t[all[i][j]]+t[all[i][j-1]];
			edge[all[i][j]].push_back({all[i][j-1],w});
			edge[all[i][j-1]].push_back({all[i][j],w});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)<<'\n';
	}
}
