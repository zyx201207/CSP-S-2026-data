#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,INF=0x3f3f3f3f;
int lg,a1,t1,c,n,m,d,qu,w[maxn],k,x,y,times;
struct Node{
	int v1,ti;
};
Node v;
vector<Node>adj[2*maxn+1005];
int dis[maxn];
void djs(int st){
	queue<int>q;
	q.push(st);
	dis[st]=0;
	while(!q.empty()){
		int u=q.front();
		for(auto v:adj[u]){
			if(dis[u]+v.ti<dis[v.v1]){
				q.push(v.v1);
				dis[v.v1]=dis[u]+v.ti;
			}
		}
		q.pop();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a1>>t1;
			adj[a1].push_back({m+i,t1});
			adj[m+i].push_back({a1,t1});
		}
	}
	for(int i=1;i<=qu;i++){
		cin>>x>>y;
		memset(dis,INF,sizeof(dis));
		times+=w[x]+w[y];
		djs(x);
		times+=dis[y];
		//cout<<dis[y]<<endl;
		//for(int i=1;i<=m;i++)cout<<dis[i]<<" ";
		//cout<<endl;
		cout<<times<<endl;
		times=0;
		lg=0;
	}
	return 0;
}
//Oct31==Dec25?
