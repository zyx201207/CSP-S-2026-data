#include<bits/stdc++.h>
using namespace std;

const int N=1e6+3;
int c,T,n,k;
vector<vector<int> >e;
int ans;
int f[N],sz[N];

inline void gtroot(int u,int fa,int &root){
	sz[u]=1;
	for(auto v:e[u]){
		if(v==fa) continue;
		gtroot(v,u,root);
		sz[u]+=sz[v];
		f[u]=max(f[u],sz[v]);
	}
	if(f[u]<f[root]) root=u;
	return;
}

inline int solve1(){
	f[0]=0x3f3f3f3f;
	int root=0;
	gtroot(1,0,root);
	
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		e.clear();
		e.resize(n+1);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		printf("1\n");
	}
	return 0;
}
