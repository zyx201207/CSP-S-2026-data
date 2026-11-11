#include<bits/stdc++.h>

#define pii pair<int,int>
using namespace std;

int read() {
	int x=0,f=1; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x*10)+(ch-'0');
	return x*f;
}

const int maxn = 4004;

int n,k;
pii edge[maxn];

vector<int> G[maxn];
int dep[maxn],dis[maxn];

int maxdep=0,midp=0;
int bbb[maxn],btop=0;

int dfs1(int u,int fa) {
	dep[u]=dep[fa]+1; dis[u]=dep[u];
	if(maxdep<dep[u]) maxdep=dep[u];
	int res=u;
	bbb[++btop]=u;
	for(auto v:G[u]) if(v!=fa) {
		int p=dfs1(v,u); dis[u]=max(dis[u],dis[v]);
		if(dep[p]>dep[res]) res=p;
	} 
	if(dep[u]==maxdep) midp=bbb[(btop+1)/2];
	bbb[btop]=0; btop--;
	return res;
}

int col[maxn];

void dfs2(int u,int fa,int c) {
	col[u]=c;
	for(auto v:G[u]) if(v!=fa) {
		dfs2(v,u,c);
	}
}

int cnt[maxn];

void work() {
	n=read(); k=read();
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<n;i++) {
		edge[i].first=read();
		edge[i].second =read();
		int u=edge[i].first,v=edge[i].second;
		G[u].push_back(v); G[v].push_back(u);
	}
	
	if(n==k) {
		cout<<0<<'\n';
		return ;
	}
	
	maxdep=0; btop=0;
	int mxp=dfs1(1,0);
	maxdep=0; btop=0;
	int tmp=dfs1(mxp,0); int rt=midp;
	maxdep=0; btop=0;
	tmp=dfs1(rt,0);
	
//	cout<<rt<<' '<<maxdep<<'\n';
//	for(int i=1;i<=n;i++) cout<<dep[i]<<'\n';
	
	
	for(int i=1;i<=n;i++) cnt[i]=0;
	for(int i=1;i<=n;i++) cnt[-dep[i]+dis[i]+1]++;
	int wst=k,ans=1e9; 
	for(int i=n;i>=1;i--) {
		if(wst>=cnt[i]) {
			wst-=cnt[i];
		} else {
			ans=i; break;
		}
	}
	
	for(int j=1;j<n;j++) {
		
//		cout<<"#case"<<j<<' '<<edge[j].first<<' '<<edge[j].second<<'\n';
		
		for(int i=1;i<=n;i++) G[i].clear(),col[i]=0,cnt[i]=0;
		for(int i=1;i<n;i++) if(i!=j) {
			int u=edge[i].first,v=edge[i].second;
			G[u].push_back(v); G[v].push_back(u);
		}
		int qwq=0; int p1=0,p2=0;
		for(int i=1;i<=n;i++) if(!col[i]) {
			qwq++; dfs2(i,0,qwq);
			if(qwq==1) p1=i;
			else p2=i;
		}
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++) if(i!=j) {
			int u=edge[i].first,v=edge[i].second;
			if(col[u]==1) {
				G[u].push_back(v); G[v].push_back(u);
			}
		}
		
		for(int i=1;i<=n;i++) dep[i]=0;
		
	maxdep=0; btop=0;
	mxp=dfs1(p1,0);
	maxdep=0; btop=0;
	tmp=dfs1(mxp,0); rt=midp;
	maxdep=0; btop=0;
	tmp=dfs1(rt,0);
	
//		cout<<"p1"<<' '<<rt<<'\n';	
		
		for(int i=1;i<=n;i++) if(dep[i]!=0) {
			if(i!=rt) cnt[-dep[i]+dis[i]+1]++;
		}
		
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++) if(i!=j) {
			int u=edge[i].first,v=edge[i].second;
			if(col[u]==2) {
				G[u].push_back(v); G[v].push_back(u);
			}
		}
		
		for(int i=1;i<=n;i++) dep[i]=0;
		
	maxdep=0; btop=0;
	mxp=dfs1(p2,0);
	maxdep=0; btop=0;
	tmp=dfs1(mxp,0); rt=midp;
	maxdep=0; btop=0;
	tmp=dfs1(rt,0);
	
//		cout<<"p2"<<' '<<rt<<'\n';		
		
		for(int i=1;i<=n;i++) if(dep[i]!=0) {
			if(i!=rt) cnt[-dep[i]+dis[i]+1]++;
		}
		
//		for(int i=1;i<=n;i++) cout<<cnt[i]<<' '; cout<<'\n';
		
		wst=k-2; for(int i=n;i>=1;i--) {
			if(wst>=cnt[i]) {
				wst-=cnt[i];
			} else { 
				ans=min(ans,i); break;
			}
		}
		
	}
	
	cout<<ans<<'\n';
	
}

void spwork() {
	n=read(); k=read();
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<n;i++) {
		edge[i].first=read();
		edge[i].second =read();
		int u=edge[i].first,v=edge[i].second;
		G[u].push_back(v); G[v].push_back(u);
	}
	if(n==k) {
		cout<<0<<'\n';
		return ;
	}
	
	int m=(n-1)/2;
	int cnt=(m+k-1)/k;
	cout<<(cnt/2)+1<<'\n';
}

int main() {
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c=read(),_=read();
	
	if(c==13||c==14) {
		while(_--) {
			spwork();
		}
		return 0;
	}
	
	while(_--) {
		work();
	}
	return 0;
}

/*

17
9
6
6
9

*/

/*
DRE4M1N9
*/

