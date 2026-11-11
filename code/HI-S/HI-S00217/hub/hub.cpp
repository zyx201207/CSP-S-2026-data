#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,mark[1000010],d[1000010],ans,f[1000010];
vector<int>v[1000010];
set<int>s;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
bool check(){
	s.clear();
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		if(mark[i]){
			for(int j:v[i]){
				if(mark[j]){
					int fx=find(i),fy=find(j);
					if(fx!=fy) f[fx]=fy;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) if(mark[i]) s.insert(f[i]);
	return s.size()>2;
}
void dfs1(int x,int fa,int D,int X){
	for(int y:v[x]){
		if(y==fa) continue;
		if(mark[y]) d[X]=min(d[X],D+1);
		else dfs1(y,x,D+1,X);
	}
}
void dfs(int x,int y){
	if(y==k){
		if(check()) return;
		for(int i=1;i<=n;i++) d[i]=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			if(!mark[i]) dfs1(i,0,0,i);
			else d[i]=0;
		}
		int dist=0;
		for(int i=1;i<=n;i++) dist=max(dist,d[i]);
		ans=min(ans,dist);
		return;
	}
	if(x==n) return;
	mark[x+1]=1;
	dfs(x+1,y+1);
	mark[x+1]=0;
	dfs(x+1,y);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) v[i].clear(),mark[i]=0;
		ans=2e9;
		for(int x,y,i=1;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
		dfs(0,0);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
