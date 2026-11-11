#include<bits/stdc++.h>//40pts 
using namespace std;
const int N=5111;
long long a[N];
long long n,m;
vector<int>g[N];
int dis[N][N],t[N][N];
void bfs(int begi){
	for(int i=1;i<=n;i++){
		t[begi][i]=0;
		dis[begi][i]=0x3f3f3f3f;
	}
	queue<int>q;
	dis[begi][begi]=0;
	t[begi][begi]=1;
	q.push(begi);
	while(!q.empty()){
		int u=q.front();
		q.pop(); 
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(dis[begi][v]<dis[begi][u]+1){
				continue;
			}
			if(dis[begi][v]==dis[begi][u]+1){
				t[begi][v]+=t[begi][u];
				continue;
			}
			dis[begi][v]=dis[begi][u]+1;
			t[begi][v]=t[begi][u];
			q.push(v);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	scanf("%*d%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++){
			g[i].clear();
			scanf("%lld",&a[i]);
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]>m){
					break;
				}
				g[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(t[i][j]==2){
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

I love Yore_Snow!!!!!

°ÝÍÐÁËÎÒÒªÀ¶¹´ 
*/
