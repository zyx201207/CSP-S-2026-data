#include<bits/stdc++.h>
#define int long long
using namespace std;
const int max_n=305,INF=0x3f3f3f3f3f3f3f3f;
struct Edge{
	int u,v,nxt;
}e[max_n*max_n];
int h[max_n],idx;
void add(int u,int v){
	e[++idx]={u,v,h[u]};
	h[u]=idx;
}
int a[max_n],dist[max_n][max_n],cnt[max_n][max_n];
int c,T;
queue<pair<int,int> > q;
int bfs(int s,int n){
	q.push({s,0});
	dist[s][s]=0;
	while(!q.empty()){
		pair<int,int> pr=q.front();
		int f=pr.first,dis=pr.second;
		//cout << f << endl;
		q.pop();
		for(int i=h[f];i;i=e[i].nxt){
			int v=e[i].v;
			if(dist[s][v]==dis+1){
				cnt[s][v]++;
				q.push({v,dist[s][v]});
			}else if(dist[s][v]==INF){
				dist[s][v]=dis+1;
				cnt[s][v]++;
				q.push({v,dist[s][v]});
			}else{
				q.push({v,dis+1});
			}
			
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(cnt[s][i]==2){
			ans++;
		}
	}
	return ans;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	int n,d,ans=0;
	for(int i=0;i<=304;i++){
		for(int j=0;j<=304;j++){
			dist[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(int t=1;t<=T;t++){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					add(i,j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans+=bfs(i,n);
		}
		printf("%lld\n",ans);
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=0x3f3f3f3f3f3f3f3f;
				cnt[i][j]=0;
			}
		}
	}
	
	
	
	return 0;
}