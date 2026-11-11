#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,m,k,R;
vector<int> g[N];
int ds[N],od[N],dep[N],FA[N];
void bfs(int x,int fa){
	dep[x]=dep[fa]+1;FA[x]=fa;
	for(int y:g[x])if(y!=fa)bfs(y,x);
}
void search_d(){
	int P,Q,mx=0;
	bfs(1,0);
	for(int i=1;i<=n;i++)if(dep[i]>mx)mx=dep[i],P=i;
	bfs(P,0);
	mx=0;
	for(int i=1;i<=n;i++)if(dep[i]>mx)mx=dep[i],Q=i;
	while(dep[Q]){
		od[Q]=1;
		ds[++m]=Q;
		Q=FA[Q];
	}
}
int val[N],ll[N],rr[N],fl[N],fr[N];
void dfs(int x,int fa,int rt){
	dep[x]=0;
	for(int y:g[x]){
		if(y==fa || od[y])continue;
		dfs(y,x,rt);
		dep[x]=max(dep[x],dep[y]+1);
	} 
	if(x!=ds[rt] && dep[x]>=R)val[rt]++;
}
bool check(){
	for(int i=1;i<=m;i++){
		val[i]=1;
		dfs(ds[i],0,i);
		int z=max(0,R-dep[ds[i]]);
		ll[i]=max(1,i-z),rr[i]=min(m,i+z);
	}
	for(int i=1;i<=m;i++){
		val[i]+=val[i-1];
		if(i<=1+R)fl[i]=1;
		else fl[i]=val[i]-val[R];
	}
	for(int i=m;i>=1;i--){
		if(i>=m-R)fr[i]=1;
		else fr[i]=val[m-R]-val[i-1];
	}
//	cout<<R<<endl;
//	for(int i=1;i<=m;i++)cout<<ll[i]<<" "<<rr[i]<<endl;
//	cout<<endl;
	for(int l=1;l<=m;l++){
		int mr=m;
		for(int r=l+1;r<=mr;r++){
			if(ll[r]>l)mr=min(mr,rr[r]);
			if(fl[l]+fr[r]<=k)return 1;
		}
	}
	return 0;
}
void solve(){
	cin>>n>>k;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	search_d();
	int l=0,r=n-1;
	while(l<r){
		R=(l+r)/2;
		if(check())r=R;
		else l=R+1;
	}
	cout<<r<<"\n";
	for(int i=1;i<=n;i++){
		g[i].clear(); 
		od[i]=0;
	}
	m=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--)solve();
	return 0;
}
