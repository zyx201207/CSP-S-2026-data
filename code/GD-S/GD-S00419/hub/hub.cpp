#include<bits/stdc++.h>
using namespace std;
const int N=4e3+5,inf=1e9;
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int C,t,n,k,sz[N],dep[N],mx[N],mx2[N],tj[N];
int x;
vector<int>G[N];
void dfs(int u,int fa){
	tj[u]=0;
	for(int v:G[u]){
		if(v==fa)continue;
		dep[v]=dep[u]+1,mx[v]=dep[v],mx2[v]=-inf;
		dfs(v,u);
		tj[u]+=tj[v];
		if(mx[v]>mx[u])mx2[u]=mx[u],mx[u]=mx[v];
		else mx2[u]=max(mx2[u],mx[v]);
	}
	if(mx[u]-dep[u]>=x)tj[u]++;
}
int query(int u,int fa,int len){
	if(len>x)return inf;
	int ans=inf;
	for(int v:G[u]){
		if(v==fa)continue;
		int y=len;
		if(mx[u]==mx[v]){
			if(mx2[u]>x)y=max(y,mx2[u]-dep[u]);
//			cout<<u<<' '<<x<<' '<<mx2[u]<<"wahduawduha8dhu\n";
		}
		else{
			if(mx[u]>x)y=max(y,mx[u]-dep[u]);
		}
		y++;
		ans=min(ans,query(v,u,y));
	}
	if(ans==inf){
		ans=1;
		for(int v:G[u]){
			if(v==fa)continue;
			ans+=tj[v];
		}
	}
	return ans;
}
bool check(){
	int ans=inf;
	for(int i=1;i<=n;i++){
		dep[i]=mx[i]=0,mx2[i]=-inf;
		dfs(i,0);
		ans=min(ans,tj[i]);
		for(int j=1;j<=n;j++){
//			cout<<i<<' '<<j<<":"<<mx[j]<<' '<<mx2[j]<<endl;
		}
		int ss=1;
		for(int v:G[i])ss+=tj[v];
		for(int v:G[i]){
			ans=min(ans,ss-tj[v]+query(v,i,-inf));
//			cout<<ss<<' '<<tj[v]<<' '<<query(v,i,-inf)<<endl;
		}
//		cout<<i<<' '<<ans<<"iksjdoajdwa\n";
	}
	return ans<=k;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	C=read(),t=read();
	while(t--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			G[u].push_back(v),G[v].push_back(u);
		}
		int r=n,l=-1;
		while(l+1<r){
			x=l+r>>1;
			if(check())r=x;
			else l=x;
		}
		printf("%d\n",r);
	}
	
	return 0;
} 
