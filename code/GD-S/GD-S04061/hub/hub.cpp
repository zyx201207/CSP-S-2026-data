#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct T{
	int to,nxt;
} edge[2*N];
int n,c,t,head[N],cnt,dis[1005][1005],k,ans,s[N],len;
bitset<N> vis,ok;
void add(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void dg(int x,int fa,int z){
	if(fa)dis[z][x]=dis[z][fa]+1;
	for(int i=head[x];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa) continue;
		dg(v,x,z);
	}
}
void bfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(!ok[v]||vis[v]) continue;
		bfs(v);
	}
}
void dfs(int x,int k){
	if(x>n){
		int sum=0;
		for(int i=1;i<=n;++i){
			int num=1e9;
			for(int j=1;j<=len;++j) num=min(num,dis[i][s[j]]);
			sum=max(sum,num);
		}
		if(sum>=ans) return;
		int cnt=0;
		for(int i=1;i<=len;++i) ok[s[i]]=1;
		for(int i=1;i<=len;++i){
			if(vis[s[i]]) continue;
			++cnt;bfs(s[i]); 
		}
		if(cnt<=2)ans=min(ans,sum);
		for(int i=1;i<=len;++i) vis[s[i]]=ok[s[i]]=0;
		return;
	}
	if(k){
		s[++len]=x;
		dfs(x+1,k-1);
		--len;
	}
	if(n-x>=k)dfs(x+1,k);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		cnt=0;
		for(int i=1;i<=n;++i) head[i]=0;
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		if(n==k){
			cout<<0<<endl;
			continue;
		}
		if(c>=13&&c<=14){
			int m=(n-1)/2;
			if(k>=m){
				cout<<1<<endl;
				continue; 
			}
			m=m-k+5;
			cout<<(m-1)/4+1<<endl;
			continue;
		}
		for(int i=1;i<=n;++i) dg(i,0,i); 
		ans=1e9;
		dfs(1,k);
		cout<<ans<<endl;
	} 
	return 0;
}
