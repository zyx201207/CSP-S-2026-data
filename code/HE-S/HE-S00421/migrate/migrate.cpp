#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=5010;
int n;
LL d,dist[N],x[N];
vector<PII> e[N];
bool st[N];
bool dijkstra(int S,int T){
//	printf("¿¼ÂÇ(%d,%d)\n",S,T);
	int cnt=0;
	for(int i=1;i<=n;i++)dist[i]=4e18,st[i]=0;
	dist[S]=0;
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push({0,S});
	while(heap.size()){
		int u=heap.top().second;
		heap.pop();
		if(st[u])continue;
		st[u]=true;
		for(int i=0;i<e[u].size();i++){
			PII it=e[u][i];
			int j=it.first;
			LL dit=it.second+dist[u];
			if(dit<dist[j]){
				dist[j]=dit;
				heap.push({dit,j});
				cnt=0;
			}else if(j==T&&dit==dist[T]){
				cnt++;
			}
		}
	}
//	printf("foot[%d]:%d\n",T,foot[T]);
//	printf("cnt:%d\n",cnt);
	return cnt==1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=1;j<i;j++){
				if(x[i]-x[j]<=d){
					e[j].push_back({i,1});
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dijkstra(i,j))cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
