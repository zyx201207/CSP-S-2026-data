#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e6;
int c,T,n;
ll d,x[N+5],res;
bool vis[N+5];
int l_bd(ll tar){
	int l=1,r=n,mid;
	while(l<r){
		mid=l+r+1>>1;
		if(x[mid]<=tar) l=mid;
		else r=mid-1;
	}
	if(x[l]>tar) return 0;
	return l;
}
int r_bd(ll tar){
	int l=1,r=n,mid;
	while(l<r){
		mid=l+r>>1;
		if(x[mid]>=tar) r=mid;
		else l=mid+1;
	}
	if(x[l]<tar) return n+1;
	return l;
}
ll dfs(int u,int v,int cnt){
	if((abs(x[v]-x[u])+d-1)/d>cnt) return 0;
	if(u==v) return 1;
	int l=max(1,r_bd(x[u]-d));
	int r=min(n,l_bd(x[u]+d));
	ll ans=0;
	for(int i=l;i<=r;i++){
		if(vis[i]) continue;
		vis[i]=1;
		ans+=dfs(i,v,cnt-1);
		if(ans>2) return 3;
		vis[i]=0;
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		res=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",x+i);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if((x[j]-x[i]+d-1)/d>j-i) continue;
				vis[i]=1;
				ll num=dfs(i,j,j-i);
				vis[i]=0;
				if(num==2) res++;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
