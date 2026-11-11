#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MaxN=1e6+5;
int C,yuanshen; 
int n,k,tot[MaxN],f[MaxN],d[MaxN],ans;
vector<int> to[MaxN];
bool flag,isd[MaxN];
void check(int x,int fa){
	if(!flag) return;
	for(auto v:to[x]){
		if(v==fa) continue;
		if(isd[v]==1&&isd[x]==0) tot[x]++;
		check(v,x);
		tot[x]+=tot[v];
		if(tot[x]>2) flag=0;
		if(flag==0) return;
	}
}
void init(int x,int fa){
	f[x]=fa,d[x]=d[fa]+1;
	for(auto v:to[x]){
		if(v==fa) continue;
		init(v,x);
	}
}
int dis(int x,int y){
	int res=0;
	if(d[x]<d[y]) swap(x,y);
	while(d[x]>d[y]) x=f[x],res++;
	if(x==y) return res;
	while(x!=y) x=f[x],y=f[y],res+=2;
	return res-1;
}
int ddd(){
	int res=0;
	for(int i=1;i<=n;i++){
		if(isd[i]!=0) continue;
	//	cout<<i<<'\n';
		int minn=1e9;
		for(int j=1;j<=n;j++){
			if(isd[j]!=1) continue;
			minn=min(minn,dis(i,j));
	//		cout<<i<<' '<<j<<' '<<dis(i,j)<<'\n';
		}
		res=max(res,minn);
	}
//	cout<<'\n';
	return res;
}
void ddfs(int X,int W){//cout<<X<<' '<<W<<'\n';
	if(k-W>n+1-X) return;
	if(W==k){
		flag=1;
		for(int i=1;i<=n;i++) tot[i]=0;
		check(1,0);
		if(!flag) return;
		ans=min(ans,ddd());
		return; 
	}
	ddfs(X+1,W);
	isd[X]=1;
//	cout<<t<<'\n';
	ddfs(X+1,W+1);
	isd[X]=0;
}
void qidong(){
	cin>>n>>k;
	if(k==n){
		cout<<"0\n";
		return;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	ans=1e9;
	init(1,0);//puts("ok");
//	puts("ok");
	ddfs(1,0);
	cout<<ans<<'\n';
	
	for(int i=1;i<=n;i++) to[i].clear();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>C>>yuanshen;
	while(yuanshen--) qidong();
	return 0;
}
