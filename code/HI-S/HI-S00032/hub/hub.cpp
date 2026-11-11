#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+10, INF=2e9;

int n,k,head[N],to[N*2],nex[N*2],cnt=0, p[N][25], d[N], tn;
bool v[N], tr[N];

void add_edge(int u, int v) {
	++cnt;
	to[cnt]=v;
	nex[cnt]=head[u];
	head[u]=cnt;
}

bool vs(int p, int id) {
	if((p>>(id-1))&1)return 1;
	else return 0;
}

void build(int x,int fa) {
	p[x][0]=fa;
	int e=head[x];
	while(e!=-1) {
		if(to[e]!=fa) {
			d[to[e]]=d[x]+1;
			build(to[e], x);
		}
		e=nex[e];
	}
}

void dfs(int x) {
	tr[x]=1;
	int e=head[x];
	while(e!=-1) {
		if(!tr[to[e]]&&v[to[e]]) {
			dfs(to[e]);
		}
		e=nex[e];
	} 
}

int lca(int x, int y) {
	if(x==y)return x;
	if(d[x]<d[y])return lca(y,x);
	
	for(int j=tn;j>=0;j--) {
		if(d[p[x][j]]>=d[y]) {
			x=p[x][j];
		}	
	}
	if(x==y)return x;
	for(int j=tn;j>=0;j--) {
		if(p[x][j]!=p[y][j]) {
			x=p[x][j],y=p[y][j];
		}
	}
	return p[x][0];
}

int dis(int x, int y) {
	int l=lca(x,y);
	return (d[x]-d[l])+(d[y]-d[l]);
}

int calc(int p) {
	for(int i=1;i<=n;i++) {
		v[i]=vs(p,i), tr[i]=0;
	}
	int c=0;
	for(int i=1;i<=n;i++) {
		if(!v[i])continue;
		if(tr[i])continue;
		++c; dfs(i);
	}
	if(c>2)return INF;
	int ans=0;
	for(int i=1;i<=n;i++) {
		int d=INF;
		for(int j=1;j<=n;j++) {
			if(!v[j])continue;
			d=min(d, dis(j, i));
		}
		ans=max(ans, d);
	}
	return ans;
}

bool judge(int x) {
	int l=(n+1)/2;
	if(((x-1)+x)>=l-1) {
		return 1;
	}
	int m=l-(x-1)-x;
	int a=m-k;
	if(((a+1)/2)<=x)return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c, t; cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		tn=(int)(log(n)/log(2));
		cnt=0;
		for(int i=1;i<=n;i++) {
			head[i]=-1;
		}
		for(int i=1;i<=n-1;i++) {
			int u, v;cin>>u>>v;
			add_edge(u,v),add_edge(v,u);
		}
		if(n==k) {
			cout<<"0\n";
			continue;
		}
		if(c==13||c==14) {
			int ans=n+1;
			for(int i=n;i>=1;i--) {
				if(judge(i))ans=i;
			}
			cout<<ans<<"\n";
			continue;
		}
		
		d[1]=0;
		build(1,0);
		for(int j=1;j<=tn;j++) {
			for(int i=1;i<=n;i++) {
				p[i][j]=p[p[i][j-1]][j-1];
			}
		}
		if(c!=13&&c!=14) {
			int ans=INF;
			for(int p=0;p<(1<<n);p++) {
				int q=0;
				for(int i=1;i<=n;i++) {
					if(vs(p,i))++q;
				}
				if(q!=k)continue;
				ans=min(ans, calc(p));
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	
	return 0;
}

//100+[92, 100]+24+[15,25]=[231,249], no any un-ordinary score, how to win?
