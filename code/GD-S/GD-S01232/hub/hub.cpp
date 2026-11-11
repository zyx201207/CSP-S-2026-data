#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>a[1000010];
int vis[1000010];
queue<int>qu;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while(t--){
		int n, k, ans=1e9;
		scanf("%d%d", &n, &k);
		for(int i=1;i<n;i++){
			int u, v;
			scanf("%d%d", &u, &v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(int i=0;i<(1<<(n+1));i+=2){
			int s1=0, s2=0, maxx=0;
			for(int j=1;j<=n;j++)if(i>>j&1){
				s1++;
				if(!vis[j]){
					s2++;
					vis[j]=j;
					qu.push(j);
					while(qu.size()){
						int u=qu.front();
						qu.pop();
						for(int v:a[u])if(!vis[v]&&(i>>v&1)){
							vis[v]=j;
							qu.push(v);
						}
					}
				}
			}
			for(int j=1;j<=n;j++)vis[j]=0;
			if(s1!=k||s2>2)continue;
			for(int j=1;j<=n;j++)if(i>>j&1){
				vis[j]=1;
				qu.push(j);
			}
			while(qu.size()){
				int u=qu.front();
				qu.pop();
				maxx=max(maxx, vis[u]);
				for(int v:a[u])if(!vis[v]){
					vis[v]=vis[u]+1;
					qu.push(v);
				}
			}
			for(int j=1;j<=n;j++)vis[j]=0;
			ans=min(ans, maxx);
		}
		printf("%d\n", ans-1);
		for(int i=1;i<=n;i++)a[i].clear();
	}
	return 0;
}
