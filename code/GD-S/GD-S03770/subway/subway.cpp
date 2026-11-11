#include<iostream>
#include<algorithm> 
#include<cstring>
#include<cstdio>
#include<vector>
#define fi first
#define se second
using namespace std;
using pii=pair<int,int>;
vector<pii> sa[500005];
vector<pii> li[505];
int c,n,m,d,q;
int w[500005];
bool fs[500005];
bool fl[505];
int dfs(char t,int x,int z){
	if(t=='s'&&z==x){
		return 0;
	}
	int mi=1e9;
	if(t=='l'){
		fl[x]=1;
		for(pii p:li[x]){
			if(fs[p.fi]){
				continue;
			}
			int D=dfs('s',p.fi,z);
			mi=min(mi,D+p.se);
		}
	}
	else{
		fs[x]=1;
		for(pii p:sa[x]){
			if(fl[p.fi]){
				continue;
			}
			int D=dfs('l',p.fi,z);
			mi=min(mi,D+p.se);
		}
	}
	return mi;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d %d",&a,&t);
			li[i].push_back({a,t});
			sa[a].push_back({i,t});
		}
	}
	while(q--){
		for(int i=1;i<=m;i++){
			fs[i]=0;
		}
		for(int i=1;i<=n;i++){
			fl[i]=0;
		}
		int x,y;
		scanf("%d %d",&x,&y);
		int ans=dfs('s',y,x);
		printf("%d\n",ans+w[x]+w[y]);
	}
	return 0;
}
