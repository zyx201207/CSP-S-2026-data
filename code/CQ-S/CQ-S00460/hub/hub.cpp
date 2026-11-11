#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int opt,tot,ans;
int t,n,k,x,y;
int b[N],fa[N],dep[N],head[N];
bool flag[N],vis[N],Vis[N];
struct node{
	int x,y;
}nex[N]; 
void add(int x,int y){
	tot++;
	nex[tot].x=y;
	nex[tot].y=head[x];
	head[x]=tot;
}
void dfs1(int node){
	for(int i=head[node];i;i=nex[i].y){
		int w=nex[i].x;
		if(w!=fa[node]){
			fa[w]=node;
			dep[w]=dep[node]+1;
			dfs1(w);
		}
	}
} 
void dfs2(int node){
	for(int i=head[node];i;i=nex[i].y){
		int w=nex[i].x;
		if(Vis[w]&&!vis[w]){
			vis[w]=true;
			dfs2(w); 
		}
	}
}
bool check(){
	int cnt=0;
	for(int i=1;i<=k;i++)
		Vis[b[i]]=true;
	for(int i=1;i<=k;i++)
		if(!vis[b[i]]){
			vis[b[i]]=true;
			dfs2(b[i]);
			cnt++;
		}
	for(int i=1;i<=k;i++){
		vis[b[i]]=false;
		Vis[b[i]]=false;
	}
	return (cnt<=2);
}
int Lca(int x,int y){
	int ans=0;
	if(dep[x]<dep[y])
		swap(x,y);
	while(dep[x]>dep[y]){
		x=fa[x];
		ans++;
	}
	while(x!=y){
		x=fa[x];
		y=fa[y];
		ans+=2; 
	}
	return ans;
}
void dfs(int x){
	if(x==k+1){
		if(!check())
			return;
		int sum=0;
		for(int i=1;i<=n;i++){
			int cnt=INT_MAX;
			for(int j=1;j<=k;j++)
				cnt=min(cnt,Lca(i,b[j]));
			sum=max(sum,cnt);
		}
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!flag[i]){
			b[x]=i;
			flag[i]=true;
			dfs(x+1);
			flag[i]=false;
		}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>opt>>t;
	while(t--){
		tot=0;
		ans=INT_MAX;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		if(n==k)
			cout<<0<<"\n";
		else if(opt==13||opt==14){
			if(k>=n/2)
				cout<<1<<"\n";
			else
				cout<<(n/2-k-1)/4+2<<"\n";
		}
		else{
			dfs1(1);
			dfs(1);
			cout<<ans<<"\n";
		}
		for(int i=1;i<=n;i++)
			head[i]=0;
		for(int i=1;i<=tot;i++)
			nex[i].x=nex[i].y=0;
	}
	return 0;
}
