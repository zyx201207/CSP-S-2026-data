#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,inf=1e17;
int n,k,f[N],h[N],vis[N],ans,c[N];
vector<int>g[N];
int dfs(int x,int fa,int d){
	h[x]=inf;f[x]=0;
	int res=0;
	for(int t:g[x]){
		if(t==fa)continue;
		res+=dfs(t,x,d);
		f[x]=max(f[x],f[t]+1);
		h[x]=min(h[t]+1,h[x]);
	}
	if(h[x]+f[x]<=d)f[x]=-inf;
	if(f[x]>=d)res++,h[x]=0,f[x]=-inf;
	return res;
}
bool chk(int x){
	return dfs(1,0,x)+(f[1]>=0)<=k; 
}
int F(int x,int fa){
	if(vis[x])return 0;
	int res=inf;
	for(int t:g[x])
		if(t!=fa)res=min(res,F(t,x)+1);
	return res;
}
void C(int x,int fa){
	if(!c[x])return;
	c[x]=0;
	for(int t:g[x])
		if(t!=fa)C(t,x);
}	
void dfs(int x){
	if(x>n){
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=vis[i],c[i]=vis[i];
		if(cnt>k)return;
		int t=0;cnt=0;
		for(int i=1;i<=n;i++)t=max(t,F(x,0));
		for(int i=1;i<=n;i++){
			if(c[i])C(i,0),cnt++;
		}
		if(cnt<=2)ans=min(ans,t);
		return;
	}
	dfs(x+1);vis[x]=1;dfs(x+1);vis[x]=0;
}
void sol(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	if(n>10){
		int l=1,r=n,res=n;
		while(l<=r){
			int mid=l+r>>1;
			if(chk(mid))r=mid-1,res=mid;
			else l=mid+1;
		}
		cout<<res<<'\n';		
	}
	else{
		ans=inf;dfs(1);cout<<ans;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T>>T;while(T--)sol(); 
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
