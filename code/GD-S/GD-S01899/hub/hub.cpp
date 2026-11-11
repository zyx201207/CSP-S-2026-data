//
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;

vector<int> e[MAXN];
int fa[MAXN],u[MAXN],v[MAXN];
bool vis[MAXN];
int vis1[MAXN];
map<int,int> mp;

int fath(int id){
	if (fa[id]==id) return id;
	return fa[id]=fath(fa[id]);
}
void mer(int x,int y){
	fa[fath(x)]=fath(y);
}

void dfs(int id){
	for (int i:e[id])
		if (!vis1[i]){
			vis1[i]=vis1[id]+1;
			dfs(i);
		}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int _,t;
	scanf("%d %d",&_,&t);
	while (t--){
		int n,k;
		scanf("%d %d",&n,&k);
		for (int i=1;i<=n;i++) e[i].clear();
		for (int i=1;i<n;i++){
			scanf("%d %d",&u[i],&v[i]);
			e[u[i]].push_back(v[i]);
			e[v[i]].push_back(u[i]);
		}
		int ans=1e9;
		for (int i=0;i<(1<<n);i++){
			for (int j=1;j<=n;j++) vis[j]=0;
			int cnt=0;
			for (int j=1;j<=n;j++)
				if ((i>>(j-1))&1){
					cnt++;
					vis[j]=1;
				}
			if (cnt!=k) continue;
			for (int j=1;j<=n;j++) fa[j]=j;
			for (int j=1;j<n;j++)
				if (vis[u[j]] and vis[v[j]])
					if (fath(u[j])!=fath(v[j]))
						mer(u[j],v[j]);
			mp.clear();
			for (int j=1;j<=n;j++)
				if (vis[j])
					mp[fath(j)]++;
			if (mp.size()!=2) continue;
			int nowans=0;
			for (int j=1;j<=n;j++){
				if (vis[j]) continue;
				for (int k=1;k<=n;k++)
					vis1[k]=0;
				dfs(j);
				int tmp=1e9;
				for (int k=1;k<=n;k++)
					if (vis[k] and vis1[k])
						tmp=min(tmp,vis1[k]);
				nowans=max(nowans,tmp);
			}
			ans=min(ans,nowans);
		}
		printf("%d\n",ans);
	}

	return 0;
}

