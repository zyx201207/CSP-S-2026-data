#include<bits/stdc++.h>
#define int long long
using namespace std;
int fa[10040],b[10040],s[10040],Max_s[10040],son[10040],nk,lian,c,T,n,k;
vector<int>adj[10040];
void dfs1(int x,int f){
	fa[x]=f;
	s[x]=1;Max_s[x]=1;
	for(int v:adj[x]){
		if(v==f)continue;
		dfs1(v,x);
		s[x]+=s[v];
		Max_s[x]=max(Max_s[x],1+Max_s[v]);
		if(Max_s[v]>Max_s[son[x]]) son[x]=v;
	}
}
bool kk(int x,int temp){
	if(b[x]==1)return 1;
	if(temp==0)return 0;
	for(int v:adj[x])
		if(kk(v,temp-1)) return 1;
	if(kk(fa[x],temp-1))return 1;
	return 0;
}
void dfs(int x,int pk){
	if(!son[x]){
		if(!kk(x,pk)){
			int xx=x,ppk=pk;
			while(ppk && xx!=1){
				xx=fa[xx];
				ppk--;
			}
			if(!kk(xx,1))lian++;
			b[xx]=1;
			nk--;	
		}
	}
	else{
		dfs(son[x],pk);
		for(int v:adj[x]){
			if(v==fa[x]||v==son[x])continue;
			dfs(v,pk);
		}
		if(!kk(x,pk)){
				int xx=x,ppk=pk;
				while(ppk && xx!=1){
					xx=fa[xx];
					ppk--;
				}
				if(!kk(xx,1))lian++;
				b[xx]=1;
				nk--;	
		}
	}
}
bool check(int q){
	nk=k;lian=0;memset(b,0,sizeof b);
	dfs(1,q);
	if(nk<0||lian>2) return 0;
	return 1;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,x,y;i<n;++i){
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		dfs1(1,0);
		int l=1,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)){
				r=mid-1;
				ans=mid;
			}
			else
				l=mid+1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}