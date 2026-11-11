#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[500005],head[300005],tot;
bool bz[300005];
int ch[300005];
struct edge{
	int to,nxt;
}a[600005];
void add(int u,int v){
	a[++tot].nxt=head[u];
	head[u]=tot;
	a[tot].to=v;
}
int ans[300005];
int dfs(int x){
	int num=0;
	for(int i=head[x];i;i=a[i].nxt){
		int v=a[i].to;
		num+=dfs(v);
	}
	num+=ch[x];
	ans[x]=num;
	return num;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>p[i];
	for(int i=n;i>=1;--i){
		if(!bz[p[i]]){
			bz[p[i]]=1;
			if(i!=n)
			add(p[i+1],p[i]);
		}
	}
	for(int i=1;i<=n;++i)ch[p[i]]++;
	dfs(p[n]);
	for(int i=1;i<=m;++i){
		if(i<m)
		cout<<ans[i]<<" ";
		else cout<<ans[i];
	}
	return 0;
}
