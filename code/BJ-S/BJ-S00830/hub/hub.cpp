#include<bits/stdc++.h>
using namespace std;
const int N=3000+10;
typedef long long ll;
struct node{
	int next,to;
}e[N*2*2];
int idx,t,n,k,tot,head[N],ans,v[N],pos,d[N],state[N],cnt;
void add(int u,int v){
	e[++tot].next=head[u];
	e[tot].to=v;
	head[u]=tot;
}
queue<int> q;
int bfs(){
	int maxx=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].next){
			int it=e[i].to;
			if(v[it]==pos||state[it]) continue;
			q.push(it);
			d[it]=d[x]+1;
			v[it]=pos;
			maxx=max(maxx,d[it]);
		}
	}
	while(!q.empty()) q.pop();
	return maxx;
}
void dfs2(int x){
	v[x]=1;
	for(int i=head[x];i;i=e[i].next){
		int it=e[i].to;
		if(v[it]||state[it]==0) continue;
		dfs2(it);
 	}
}
void dfs(int cur,int c){
	if(cur>n){
		if(c!=k) return ;
		for(int i=1;i<=n;i++) v[i]=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			if(state[i]&&v[i]==0){
				dfs2(i);
				cnt++;
			}
		}
		//cout<<cnt<<'\n';
		if(cnt>2) return ;
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++) v[i]=d[i]=0;
		pos=1;
		for(int i=1;i<=n;i++){
			if(state[i]){
				v[i]=1;
				d[i]=0;
				q.push(i);
		//		cout<<i<<" ";
			}
		}
		//cout<<'\n';
		ans=min(ans,bfs());
		return ;
	}
	state[cur]=0;
	dfs(cur+1,c);
	state[cur]=1;
	dfs(cur+1,c+1);
	state[cur]=0;
}
void work(){
	while(!q.empty()) q.pop();
	cin>>n>>k;
	tot=pos=0;
	ans=2e9;
	for(int i=1;i<=n;i++) head[i]=v[i]=d[i]=state[i]=0;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	if(k==2){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				if(x==y) continue;
				pos++;
				q.push(x);
				q.push(y);
				v[x]=v[y]=pos;
				d[x]=d[y]=0;
				ans=min(ans,bfs());
			}
		}
		cout<<ans<<'\n';
	}else{
		dfs(1,0);
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>idx>>t;
	while(t--) work();
	return 0;
}
