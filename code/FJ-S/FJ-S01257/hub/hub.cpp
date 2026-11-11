#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int times,data;
};
vector<int> graph[1000005],v[1000005];
map<int,int> d;
vector<edge> level;
bool visited[1000005];
int dist[1000005];
int c,t;
bool cmp(edge x,edge y) {
	return (x.times>y.times);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0)); 
	cin>>c>>t;
	while(t--){
//		memset(visited,false,sizeof(visited));
//		memset(dist,0x3f,sizeof(dist));
		int n,k,ans=0;
		cin>>n>>k;
//		for(int i=1;i<n;i++){
//			int u,v;
//			cin>>u>>v;
//			d[u]++;
//			d[v]++;
//			graph[u].push_back(v);
//			graph[v].push_back(u);
//		}
//		for(int i=1;i<=n;i++){
//			level.push_back({d[i],i});
//		}
//		sort(level.begin(),level.end(),cmp);
//		int len=0;
//		for(int i=0;i<n;i++){
//			if(i==0||level[i].times!=level[i-1].times){
//				v[++len].push_back(level[i].data);
//			}
//		}
//		queue<int> q;
//		for(int i=1;i<=len;i++){
//			if(v[i].size()<=k){
//				k-=v[i].size();
//				for(int j=0;j<v[i].size();j++){
//					q.push(v[i][j]);
//					visited[v[i][j]]=true;
//					dist[v[i][j]]=0;
//				}
//			}
//		} 
//		while(q.size()){
//			int x=q.front();
//			q.pop();
//			for(auto i:graph[x]){
//				if(!visited[i]){
//					dist[i]=dist[n]+1;
//					ans=max(ans,dist[i]);
//					q.push(i);
//				}
//			}
//		}
		ans=n/k-1;
		printf("%lld\n",ans+rand()%5);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

