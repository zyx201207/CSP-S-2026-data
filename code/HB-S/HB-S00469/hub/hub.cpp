#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int c,t,n,k,cnt,ans,ANS;
int book[N],flag[N],peek[N];
vector<int> mp[N];
struct node{
	int idx,step;
};
queue<node> q;
void bfs(){
	int link[N]={};
	while(!q.empty()){
		node h=q.front();
		q.pop();
		if(flag[h.idx]==1){
			ans=max(ans,h.step);
			return;
		}
		link[h.idx]=1;
		for(int i=0;i<(int)mp[h.idx].size();++i){
			int v=mp[h.idx][i];
			if(v==0) continue;
			if(!link[v]){
				q.push({v,h.step+1});
			}
		}
	}
}
void repe(int x){
	if(x==0) return;
	peek[x]=1;
	for(int i=0;i<(int)mp[x].size();++i){
		int y=mp[x][i];
		if((flag[y]&&!peek[y])||y==0){
			repe(y);
		}
	}
}
void check(){
	int res=0;
	memset(peek,0,sizeof peek);
	for(int i=1;i<=k;++i){
		if(!peek[book[i]]){
			res++;
			repe(book[i]);
		}if(res>2) return;
	}for(int i=1;i<=n;++i){
		if(flag[i]) continue;
		while(!q.empty()) q.pop();
		q.push({i,0});
		bfs();
	}ANS=min(ANS,ans);
}
void dfs(int s,int x){
	if(s==n+1){
		ans=0;
		if(x==k) check();
		return;
	}book[++cnt]=s;
	flag[s]=1;
	dfs(s+1,x+1);
	flag[s]=0;
	cnt--;
	dfs(s+1,x);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		memset(mp,0,sizeof mp);
		for(int i=1,u,v;i<n;++i){
			scanf("%d%d",&u,&v);
			mp[u].push_back(v);
			mp[v].push_back(u);
		}ANS=INT_MAX;
		dfs(1,0);
		printf("%d\n",ANS);
	}
	
	return 0;
}
