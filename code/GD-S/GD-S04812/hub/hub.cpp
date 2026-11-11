#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pa; 
const int MAXN=1e6+5;
int t,n,k;
vector<int> vec[MAXN],spt;
char vis[MAXN],hl[MAXN];

bool dfs(int p,int d,int p2,int &pp1,int &pp2,int dep) {
	if(vis[p]) return 0;
	vis[p]=1;
	if(p==p2) return 1;
	bool flag=0;
	for(auto i:vec[p]) {
		flag|=dfs(i,d+1,p2,pp1,pp2,dep);
	}
	if(flag) {
		if(d==(dep/k)-1) {
			pp1=p;
		} else if(d==dep-(dep/k)-1) {
			pp2=p;
		}
	}
	return flag;
}

bool dfs2(int p,int l,int pp1,int pp2) {
	//printf("%d %d %d %d\n",p,l,pp1,pp2);
	if(vis[p]) return 0;
	vis[p]=1;
	if(p==pp2) return 1;
	bool flag=0;
	for(auto i:vec[p]) {
		flag|=dfs2(i,p,pp1,pp2);
	}
	if(flag) {
		if(l==pp1) {
			spt.push_back(p);
		}
	}
	return flag;
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	scanf("%d%d",&t,&t);
for(int _=0;_<t;_++) {
	scanf("%d%d",&n,&k);
	// 0:存图
	spt.clear();
	for(int i=1;i<=n;i++) {
		vec[i].clear();
	}
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	// 1:找直径
	int p1=1,dp1=1;
	memset(vis,0,n+1);
	queue<pa> que;
	que.push(pa(p1,dp1));
	while(!que.empty()) {
		auto f=que.front();
		que.pop();
		if(vis[f.first]) continue;
		vis[f.first]=1;
		if(f.second>dp1) {
			dp1=f.second;
			p1=f.first;
		}
		for(auto i:vec[f.first]) {
			que.push(pa(i,f.second+1));
		}
	}
	memset(vis,0,n+1);
	int p2=p1,dp2=1;
	que.push(pa(p2,dp2));
	while(!que.empty()) {
		auto f=que.front();
		que.pop();
		if(vis[f.first]) continue;
		vis[f.first]=1;
		if(f.second>dp2) {
			dp2=f.second;
			p2=f.first;
		}
		for(auto i:vec[f.first]) {
			que.push(pa(i,f.second+1));
		}
	}
	// 2:记路径，找节点
	memset(vis,0,n+1);
	int pp1=0,pp2=0;
	hl[p1]=2;
	hl[p2]=2;
	spt.push_back(p1);
	spt.push_back(p2);
	dfs(p1,0,p2,pp1,pp2,dp2); // 接下来填上剩下的k-2个点
	//printf("==%d %d %d %d %d\n",p1,p2,pp1,pp2,dp2);
	memset(vis,0,n+1);
	for(int i=1;i<=k-2&&i<=dp2-2-2*(dp2/k);i++) {
		if(i&1) dfs2(pp1,pp1,pp1,pp2);
		else dfs2(pp2,pp2,pp2,pp1); 
	}
	for(int i=1;i<=k-2-(dp2-2-2*(dp2/k));i++) {
		if(i&1) dfs2(pp1,pp1,pp1,p1);
		else dfs2(pp2,pp2,pp2,p2); 
	}
	// 3:求通勤半径
	memset(vis,0,n+1);
	for(auto i:spt) {
		//printf("%d ",i);
		hl[i]=2;
		que.push(pa(i,0));
	}
	int rr=0;
	while(!que.empty()) {
		auto f=que.front();
		que.pop();
		if(vis[f.first]) continue;
		vis[f.first]=1;
		if(f.second>rr) rr=f.second;
		for(auto i:vec[f.first]) {
			if(hl[i]!=2)
			que.push(pa(i,f.second+1));
		}
	}
	printf("%d\n",rr);
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
