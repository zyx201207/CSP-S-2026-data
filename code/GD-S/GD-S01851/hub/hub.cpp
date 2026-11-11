#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,s;
}cnt[1000010];
int c,t,n,k,u,v,m=0,b,d,f[1000010],q;
vector<int> e[1000010];
bool cmp(node x,node y){
	return x.s>y.s;
}
bool chck(int u){
	for(int v:e[u]){
		if(v==d) return 0; 
	}
	return 1;
}
void dfs(int u){
	for(int v:e[u]){
		if(f[v]!=-2||f[v]==-1||f[u]+1<f[v]){
			if(f[v]==0)
			f[v]=-2;
			else f[v]=f[u]+1;
			dfs(v);
			f[v]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			cnt[u].s++;
			cnt[v].s++;
			cnt[i].id=i;
			f[i]=-1;
		}
		cnt[n].id=n;
		sort(cnt+1,cnt+1+n,cmp);
		b=cnt[1].id;
		m++;
		for(int i=2;i<=k&&m<=2;i++){
			d=cnt[i].id;
			f[i]=0;
			if(chck(b)) m++;
		}
		dfs(b);
		dfs(d);
		q=-1;
		for(int i=1;i<=n;i++) q=max(q,f[i]);
		cout<<q<<"\n";
	}
	return 0;
} 
