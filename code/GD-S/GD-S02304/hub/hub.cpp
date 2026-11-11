#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N=20,inf=1e9;

int c,T,n,k,p[N],st[N],cnt,dis[N][N],ans;
vector<int> e[N];

void color(int u,int c){
	st[u]=c;
	for (auto j:e[u])
		if (st[j]==-1)
			color(j,c);
}

void dfs(int u,int fa,int rt,int d){
	dis[rt][u]=d;
	for (auto j:e[u])
		if (j^fa)
			dfs(j,u,rt,d+1);
}

void work(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		e[i].clear(),p[i]=i;
	for (int i=1,u,v;i<n;i++)
		cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
	for (int i=1;i<=n;i++)
		dfs(i,0,i,0);
	ans=inf;
	do{
		bool ok=1;
		for (int i=2;i<=k&&ok;i++)
			if (p[i]<p[i-1])
				ok=0;
		if (!ok)
			continue;
		for (int i=1;i<=n;i++)
			st[i]=0;
		for (int i=1;i<=k;i++)
			st[p[i]]=-1;
		cnt=0;
		for (int i=1;i<=n;i++)
			if (st[i]==-1)
				color(i,++cnt);
		if (cnt>2)
			continue;
		int v=0;
		for (int i=1;i<=n;i++){
			int now=inf;
			for (int j=1;j<=k;j++)
				now=min(now,dis[i][p[j]]);
			v=max(v,now);
		}
		ans=min(ans,v);
	}while (next_permutation(p+1,p+n+1));
	cout<<ans<<"\n";
}

int main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>T;
	while (T--)
		work();
	return 0;
} 


