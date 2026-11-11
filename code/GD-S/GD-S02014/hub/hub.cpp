#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,q,n,k,x,y,a[1000005],f[1000005],fa[1000005],t[1000005],g[100005],cnt,s;
vector<int>e[1000005];
void dfs4(int x,int d){
	if(d<=f[x]) return ;
	f[x]=d;
	for(int i:e[x]) dfs4(i,d-1);
}
void dfs(int x,int fath,int d){
	fa[x]=fath;
	for(int i:e[x])
		if(i!=fath) dfs(i,x,d);
	if(!f[x]){
		for(int i=1;i<=d&&fa[x]!=-1;i++) x=fa[x];
		dfs4(x,d+1),s++,a[x]=1,g[++cnt]=x;
	}
}
void dfs2(int x,int d){
	if(f[x]>=0) return ;
	if(a[x]) d=0;
	f[x]=d;
	for(int i:e[x]) dfs2(i,d+1);
}
int dfs3(int x,int y,int d){
	if(x==y) return d;
	if(a[x]||f[x]) return -1;
	f[x]=1;
	int zd=-1;
	for(int i:e[x]) zd=max(dfs3(i,y,d+1),zd);
	return zd;
}
bool ch(int x){
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	s=cnt=0;
	dfs(1,-1,x);
	dfs2(1,1);
	int m=0;
	for(int i=1;i<=cnt;i++)
		for(int j=i+1;j<=cnt;j++){
			memset(f,0,sizeof(f));
			int zd=-1;
			for(int l:e[g[i]]) zd=max(zd,dfs3(l,g[j],1));
			if(zd!=-1) t[++m]=zd;
		}
	sort(t+1,t+1+m);
	for(int i=1;i<m;i++) s+=t[i];
	return s<=k;
}
int er(){
	int l=0,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(ch(mid)) r=mid;
		else l=mid+1;
	}
	return l;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>q;
	while(q--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		cout<<er()<<"\n";
	}
	return 0;
}
