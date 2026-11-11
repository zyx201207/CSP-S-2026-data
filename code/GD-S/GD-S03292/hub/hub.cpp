#include<bits/stdc++.h>
using namespace std;
int T;
int  c,n,k;
vector<int >e[100010];
int a[1010];
int ans;
int vis[1010];
struct node{
	int l,r;
}E[1010];
int fa[1010];
int fd(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=fd(fa[x]);
}
void me(int x,int y){
	if(fd(x)!=fd(y)){
		fa[fd(x)]=fd(y);
	}
}
int le;
int d[1010];
void fr1(int x,int f){
	if(f)d[x]=d[f]+1;
	for(int v : e[x]){
		if(v!=f&&vis[v]){
			fr1(v,x);
		}
	}
	
}
void dfs(int t){
	
	if(t>k){
		for(int i=0;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<n;i++){
			if(vis[E[i].l]&&vis[E[i].r]){
				me(E[i].r,E[i].l);
			}
			
		}
		int li=0;
		int op,od;
		for(int i=1;i<=n;i++){
			if(vis[i]&&fa[i]==i){
				od=op;
				op=i;
				li++;
			} 
		}
		if(li==2){
			fr1(op,0);
			int g=0,q;
			for(int i=1;i<=n;i++){
				if(d[i]>g){
					g=d[i];
					d[i]=0; 
				}
				
			}
			fr1(g,0);
			for(int i=1;i<=n;i++){
				if(d[i]>g){
					g=d[i];
					d[i]=0; 
				}
				
			}
//			cout<<g<<" ";
			q=g;
			fr1(od,0);
			for(int i=1;i<=n;i++){
				if(d[i]>g){
					g=d[i];
					d[i]=0; 
				}
				
			}
//			cout<<g<<" ";
			fr1(g,0);
			for(int i=1;i<=n;i++){
				if(d[i]>g){
					g=d[i];
					d[i]=0; 
				}
				
			}
//			cout<<g+q<<"\n";
			 ans=min(ans,g+q);
		}
//		
//		cout<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		a[t]=i;
		
		dfs(t+1);
		a[t]=0;	
		vis[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=1e9;
		memset(a,0,sizeof a);
		memset(vis,0,sizeof vis);
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int l,r;
			cin>>l>>r;
			E[i].l=l;
			E[i].r=r;
			e[l].push_back(r);
			e[r].push_back(l);
			
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
