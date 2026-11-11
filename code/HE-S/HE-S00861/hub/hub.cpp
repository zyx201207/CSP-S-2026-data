#include<bits/stdc++.h>
using namespace std;
const int N=300+10;
int n,k;
vector<int>e[N];
int d[N][N],y[N];
int ta[N],tot;
bool st[N];
int q[(int)1e6];
void bfs(int s){
	int hh=1,tt=0;
	d[s][s]=0;
	q[++tt]=s;
	while(hh<=tt){
		int u=q[hh++];
		for(int j:e[u]){
			if(d[j][s]==-1){
				d[j][s]=d[u][s]+1;
				q[++tt]=j;
			}
		}
	}
}
bool check(){
	int id=0;
	for(int i=1;i<=n;i++) if(st[i]) y[++id]=i;
	int tot=k;
	for(int i=1;i<=k;i++){
		for(int j:e[i]){
			
		}
	}
}
void dfs(int i,int cnt){
	if(cnt==k){
		//
		return;
	}
	if(i>n){
		
		return;
	}
	st[i]=0;
	dfs(i+1,cnt);
	st[i]=1;//iÊôÓÚS 
	dfs(i+1,cnt+1);
	st[i]=0;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		memset(d,-1,sizeof d);
		for(int i=1;i<=n;i++)bfs(i);
		
	}
	return 0;
}
