#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5,S=1<<10;
int c,t,n,k,x,y,ans,mxdep,who[N],num[N+5],to[22][N],cnt[S+5],fa[N],dep[N];
vector<int>E[N];
void dfs(int now,int f){
	dep[now]=dep[f]+1,fa[now]=f;
	to[0][now]=f;
	for(int i=1;i<=20;++i) to[i][now]=to[i-1][to[i-1][now]];
	mxdep=max(mxdep,dep[now]);
	for(int i:E[now]){
		if(i==f) continue;
		dfs(i,now);
	}
}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=num[dep[x]-dep[y]];~i;--i) if(dep[to[i][x]]>=dep[y]) x=to[i][x];
	if(x==y) return x;
	for(int i=num[dep[x]];~i;--i) if(to[i][x]!=to[i][y]) x=to[i][x],y=to[i][y];
	return to[0][x];
}
inline int dist(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
inline void work(int s){
	int cnt=k;
	for(int i=2;i<=n;++i) if(((s>>i-1)&1)&&((s>>fa[i]-1)&1)) --cnt;
	if(cnt>2) return;
	int tmp=0,tp;
	for(int i=1;i<=n;++i){
		if((s>>i-1)&1) continue;
		tp=n;
		for(int j=1;j<=n;++j) if((s>>j-1)&1) tp=min(tp,dist(i,j));
		tmp=max(tmp,tp);
	}
	ans=min(ans,tmp);
}
inline bool cmp(int x,int y){return dep[x]>dep[y];}
inline bool check(int mid){
	vector<int>v;
	v.clear(); 
	bool flag;
	for(int i=1,x;i<=n;++i){
		flag=false;
		for(int j:v) flag|=(dist(j,who[i])<=mid);
		if(flag) continue;
		if(!flag&&v.size()==k) return false;
		x=who[i];
		for(int j=20;~j;--j) if((mid>>j)&1) x=to[j][x];
		v.push_back(x);
	}
	return true;
}
inline bool check2(int mid){
	if(mid==1) return (k>=n/2);
	int l=mid,r=(n+1)/2-mid;
	if(r-l+1<=k) return true;
	int x=(r-l+1)-k;
	x=(x+1)/2;
	if(x+1<=mid) return true;
	return false;
}
inline void solve(){
	cin>>n>>k,mxdep=0;
	bool op=(n%2==1);
	int temp=n/2;
	for(int i=1;i<n;++i){
		cin>>x>>y;
		if(i<=temp) op&=(x==i&&y==i+1);
		else op&=(x==i-temp&&y==i+1);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	if(k==n){
		cout<<"0\n";
		return;
	}
	dfs(1,0);
	ans=mxdep;
	if(k<=2){
		for(int i=1;i<=n;++i) who[i]=i;
		sort(who+1,who+1+n,cmp);
		int l=0,r=mxdep,mid;
		while(l+1!=r){
			mid=l+r>>1;
			if(check(mid)) r=mid;
			else l=mid;
		}
		cout<<r<<"\n";
	}
	else if(n<=10){
		int mx=1<<n;
		for(int j=1;j<mx;++j) if(cnt[j]==k) work(j);
		cout<<ans<<"\n";
	}
	else if(op){
		int l=0,r=mxdep,mid;
		while(l+1!=r){
			mid=l+r>>1;
			if(check2(mid)) r=mid;
			else l=mid;
		}
		cout<<r<<"\n";
	}
	else cout<<mxdep<<"\n";
	for(int i=1;i<=n;++i) E[i].clear();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=2;i<=N;++i) num[i]=num[i>>1]+1;
	for(int i=1;i<=S;++i) cnt[i]=cnt[i>>1]+(i&1);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
