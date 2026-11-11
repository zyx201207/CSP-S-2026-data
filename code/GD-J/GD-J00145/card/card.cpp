#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,cnt;
int to[N],nxt[N],head[N];
int lst[N],a[N],ans[N],siz[N];
void add(int u,int v){
	cnt++;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;	
}void dfs(int x){
	siz[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		dfs(to[i]);
		siz[x]+=siz[to[i]];
	}ans[a[x]]+=siz[x];
	return ;
}int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(lst[a[i]]==0) lst[a[i]]=i;
		add(lst[a[i]]+1,i);
	}dfs(n+1);
	for(int i=1;i<m;i++) cout<<ans[i]<<" ";
	cout<<ans[m];
	return 0;
}
