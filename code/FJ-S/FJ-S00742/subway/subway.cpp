#include<bits/stdc++.h>
using namespace std;

const int M = 5e5+10;
const int N = 510;

struct node{
	int to,ne,len;
}e[M];

int K;
int pre[N];
int t[M][N];
int c,n,m,d,q;
long long w[M];
bool f[M];
int k;
long long ans = 0;
int be,ed;

void add(int u,int v,int len){
	K++;
	e[K].to = v;
	e[K].ne = pre[u];
	e[K].len = len;
	pre[u] = K;
}

void dfs(int u,long long times){
	if(u == ed){
		if(ans == -1 || ans>times){
			ans = times;
		}
		return;
	}
	for(int i = pre[u];i;i = e[i].ne){
		int to = e[i].to;
		if(!f[to]){
			f[to] = true;
			dfs(to,e[i].len+times);
			f[to] = false;
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1;i<=m;i++){
    	scanf("%lld",&w[i]);
	}
	bool is2 = true;
	for(int i = 1;i<=n;i++){
	    scanf("%d",&k);
	    if(k>2){
	    	is2 = false;
		}
	    int x,lx = -1;
	    long long tm,ltm = -1;
		scanf("%d%lld",&lx,&ltm);
		for(int j = 2;j<=k;j++){
			scanf("%d%lld",&x,&tm);
			add(lx,x,ltm+tm);
		}
	}
	while(q--){
		ans = -1;
		scanf("%d%d",&be,&ed);
		f[be] = true;
		dfs(be,w[be]+w[ed]);
		f[be] = false;
		printf("%lld\n",ans);
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
