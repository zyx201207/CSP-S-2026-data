#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXM=2e5+5;
int n,m,a[MAXN],id[MAXM],vis[MAXM],ans[MAXM],cnt[MAXM];
vector<int> g[MAXN],v; 
inline int read(){
	char ch=getchar();int num=0;
	while(ch<'0' || ch>'9') ch=getchar();
	while('0'<=ch && ch<='9') num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return num;
}
inline void dfs(int x,int dp){
	bool ok=0;
//	cout<<x<<' '<<dp<<endl;
	if(!vis[a[x]]) vis[a[x]]=1,ok=1;
	for(int i=1;i<=m;i++){
		if(vis[i]) ans[i]++;
	}
//	cout<<endl;
	bool flag=0;
	for(auto i:g[x]){
		dfs(i,dp+1);
		flag=1;
	}
	if(ok){
		vis[a[x]]=0;
//		v.pop_back();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read(); 
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=n;i>=1;i--){
		if(!id[a[i]]) g[i+1].push_back(i);
		else g[id[a[i]]].push_back(i);
		id[a[i]]=i;
	}
	dfs(n,0);
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
//kongbeiqie
