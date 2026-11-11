#include<bits/stdc++.h>
using namespace std;
bool vs[1000005];
int c,t,n,m,k,x,y,l,r,len,cnt,fa[1000005],vis[1000005],h[1000005],w[1000005],nxt[2000005],u[2000005],maxd[1000005],tong[1000005];
vector<int> zj;
stack<int> s;
void push_back(int x,int y){
	nxt[w[x]]=++m,nxt[m]=0,w[x]=m,u[m]=y;
	if(!h[x]) h[x]=m;
}
void getzhijing(int x,int y){
	vis[x]=1;
	if(!l || len<y) l=x,len=y;
	for(int it=h[x];it;it=nxt[it]) if(!vis[u[it]]) getzhijing(u[it],y+1);
}
bool getzhijing2(int x){
	vis[x]=1;
	if(x==l){
		vis[x]=-1,zj.push_back(x);
		return true;
	}
	for(int it=h[x];it;it=nxt[it]){
		if(!vis[u[it]]){
			if(getzhijing2(u[it])){
				vis[x]=-1,zj.push_back(x);
				return true;
			}
		}
	}
	return false;
}
void dfs(int x,int c){
	maxd[x]=0;
	for(int it=h[x];it;it=nxt[it]) if(vis[u[it]]!=-1 && fa[x]!=u[it]) fa[u[it]]=x,dfs(u[it],c),maxd[x]=max(maxd[x],maxd[u[it]]+1);
	if(maxd[x]>=c) cnt++;
}
bool check(int x){
	int n=zj.size(),minn=1e9,ls=x+1,rs=n-x-2;
	if(ls>rs) return true;
	cnt=2;
	for(int i=0;i<n;i++) tong[i]=n,vs[i]=false;
	for(int i=ls;i<=rs;i++){
		dfs(zj[i],x);
		if(maxd[zj[i]]>=x) tong[i]=i,cnt--;
		else if(i-(x-maxd[zj[i]])>=ls && i+(x-maxd[zj[i]])<=rs) tong[i-(x-maxd[zj[i]])]=min(tong[i-(x-maxd[zj[i]])],i+(x-maxd[zj[i]]));
	} 
	while(!s.empty()) s.pop();
	for(int i=rs;i>=ls;i--) if(tong[i]<=rs && (s.empty() || tong[i]<s.top())) s.push(tong[i]),vs[i]=true;
	if(s.empty()) return cnt<=k;
	minn=rs-s.top()+1;
	for(int i=x;i<=n-x-1;i++){
		if(vs[i]) s.pop();
		if(!s.empty()) minn=min(minn,rs-s.top()+i-ls+2);
		else minn=min(minn,i-ls+1);
	}
	return minn+cnt<=k;
}
int erfen(){
	int l=0,r=n-1;
	while(l<r){
		if(check((l+r)/2)) r=(l+r)/2;
		else l=(l+r)/2+1;
	}
	return l;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k,m=len=0,zj.clear();
		for(int i=1;i<=n;i++) fa[i]=vis[i]=h[i]=w[i]=maxd[i]=0;
		for(int i=1;i<n;i++) cin>>x>>y,push_back(x,y),push_back(y,x);
		getzhijing(1,0),r=l,l=len=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		getzhijing(r,0),len=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		getzhijing2(r);
		cout<<erfen()<<'\n';
	}
	return 0;
} 
