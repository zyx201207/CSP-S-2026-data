#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
const int M=5e5+5;
int c,n,m,d,q,w[M],vi[M];
vector<pii>g[M];
void add(int u,int v,int a){
	g[u].push_back({v,a});
	g[v].push_back({u,a});
}
void dijkstra(int s,int e){
	priority_queue<pii,vector<pii>,greater<pii>>q;
	memset(vi,0x3f,sizeof vi);
	vi[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int qf=q.top().fir,qs=q.top().sec;
		q.pop();
		for(pii i:g[qs]){
			if(i.sec+qf<vi[i.fir]){
				vi[i.fir]=i.sec+qf;
				q.push({vi[i.fir],i.fir});
			}
		}
	}
	cout<<w[s]+w[e]+vi[e]<<endl;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,la=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,v;
			cin>>a>>v;
			add(a,a+i*m,v);
			if(la) add(la+i*m,a+i*m,0);
			la=a;
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		dijkstra(s,e);
	}
	return 0;
}
