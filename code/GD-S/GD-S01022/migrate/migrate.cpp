#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,n,nxt[N],a[N],ans,vis[N],d,sum0,sum1,tag1[N],tag0[N],s;
vector<int> e[N];
void dfs(int x,int fa){
	tag0[x]=sum0;
	tag1[x]=sum1;
	vis[x]=1;
	ans+=sum1;
	if(fa){
		int w=max(nxt[x-1]-x,0ll),w2=0;
		if(x>=2)w2=max(nxt[x-2]-x,0ll);
		if(nxt[x]==nxt[x-1]){
			if(w==w2){
				sum0=sum1=0;
			}else{
				sum1=sum0;
				sum0=0;
				sum1+=(fa-x-w2);
			}
		}else{
			sum0+=(fa-x-w);
			sum1+=(w-w2);
		}
	}
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		dfs(y,x);
	}
	sum0=tag0[x];
	sum1=tag1[x];
}
void solve(){
	scanf("%lld %lld",&n,&d);
	sum0=sum1=ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		vis[i]=nxt[i]=0;
		e[i].clear();
		tag0[i]=tag1[i]=0;
	} 
	for(int i=1;i<n;i++){
		if(a[i+1]>(a[i]+d))continue;
		nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		e[nxt[i]].push_back(i);
	}
	for(int i=n;i>=1;i--){
		if(!vis[i]){
			s=i,dfs(i,0);
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		solve();
	} 
	return 0;
}/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17

*/
