#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,T,n,k,ans=1e9,big;
int f[N],fa[N],siz[N];
bool vis[N];
vector<int> s[N];
void cheak(int x,int fa){
	if(vis[x]){
		for(int to:s[x]){
			if(to==fa)continue;
			cheak(to,x);
			f[x]=min(f[x],f[to]+1);
		}
		big=max(big,f[x]);
		f[x]=0;
	}
	else{
		int max1=0,max2=0;
		for(int to:s[x]){
			if(to==fa)continue;
			cheak(to,x);
			if(max1<=f[to]){
				max2=max1;
				max1=f[to];
			}
			else if(max2<f[to]){
				max2=f[to];
			}
		}
		f[x]=max1+1;
		big=max(big,max1+max2+1);
	}
	big=max(big,f[x]);
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return 0;
	else if(siz[x]>siz[y]){
		swap(x,y);
	}
	fa[x]=y;
	siz[y]+=siz[x];
	return 1;
}
void pd(){
	for(int i=1;i<=n;i++){
		f[i]=1;
	}
	big=0;
	int now=k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])continue;
		for(int j=i+1;j<=n;j++){
			if(!vis[j])continue;
			now-=merge(i,j);
		}
	}
	if(now<=2){
		cheak(1,0);
	}
	ans=min(ans,big);
}
void dfs(int x,int cnt){
	if(cnt+n-x+1<k)return;
	if(cnt==k){
		pd();
		return;
	}
	if(x>n)return;
	vis[x]=1;
	dfs(x+1,cnt+1);
	vis[x]=0;
	dfs(x+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ans=1e9;
		for(int i=1;i<=n;i++){
			s[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			s[u].push_back(v);
			s[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	
	return 0;
}
