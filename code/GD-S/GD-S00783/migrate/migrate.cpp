#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=305;
const int N2=1000005;
int c,t;
struct node2{
	int dis,num;
};
node2 d[N][N];
int n,D;
int a[N2]; 
struct node{
	int dis,id;
};
queue<node>q;
vector<int>g[N];
void bfs(int st){
	while(q.size()){
		int id=q.front().id,dis=q.front().dis;
		q.pop();
		for(int i=0;i<g[id].size();i++){
			int v=g[id][i];
			if(dis+1<d[st][v].dis){
				d[st][v]={dis+1,1};	
				q.push({dis+1,v});
			}else if(dis+1==d[st][v].dis){
				d[st][v].num++;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c >> t;
	while(t--){
		cin >>n >> D;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
			for(int j=1;j<=n;j++){
				d[i][j]={0x3f3f3f3f,0};
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=D){
					g[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			q.push({0,i});
			bfs(i);
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(d[i][j].num==2) ans++;
			}
		}
		cout << ans <<endl;
	} 
} 
