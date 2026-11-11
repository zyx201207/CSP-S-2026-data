#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN=1e6+5;
int c,T;
int n,k;
vector <int> e[MAXN];
int f[MAXN],f2[MAXN],dis[MAXN];
int cnt=0,mid=0;
void dfs(int u,int fa){
	f2[u]=1;
	for (int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if (v==fa) continue;
		f[v]=f[u]+1;
		dfs(v,u);
		f2[u]=max(f2[u],f2[v]+1);
	}
	if (max(dis[u],f2[u])>mid && f[u]>mid) cnt++;
	return;
}
queue <int> q;
void bfs(int s,int p){
	while (s--){
		int u=q.front();
		q.pop();
		for (int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if (dis[v]) continue;
			dis[v]=p+1;
			q.push(v);
		}
	}
	if (!q.empty()) bfs(q.size(),p+1);
}
bool check(){
	for (int i=1;i<=n;i++){
		f[i]=1,cnt=0;
		dfs(i,-1);
		cnt=0;
		for (int j=1;j<=n;j++){
			if (f2[j]>mid) cnt++;
		}
		if (cnt<=k) return true;
	}
	for (int i=1;i<=n;i++){
		cnt=0,f[i]=1;
		dfs(i,-1);
//		cout<<i<<" "<<mid<<" "<<cnt<<endl;
//		for (int j=1;j<=n;j++) cout<<"u="<<j<<" "<<dis[j]<<" "<<f2[j]<<" "<<f[j]<<endl;
		if (cnt<=k) return true;
	}
	return false;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&T);
	while (T--){
		scanf("%d %d",&n,&k);
		for (int i=1;i<=n;i++) e[i].clear();
		for (int i=1;i<n;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		memset(dis,0,sizeof(dis));
		for (int i=1;i<=n;i++){
			if (e[i].size()==1){
				q.push(i);
				dis[i]=1;
			}
		}
		bfs(q.size(),1);
//		for (int i=1;i<=n;i++) cout<<dis[i]<<" ";
//		cout<<endl;
		int l=0,r=n;
		while (l<=r){
			mid=(l+r)/2;
			if (check()) r=mid-1;
			else l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}
//RP++;

