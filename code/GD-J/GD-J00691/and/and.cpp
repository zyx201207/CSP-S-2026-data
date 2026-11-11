#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
ll a,m,x[N],vis[N],ans=-2e9,p=1;
bool cmp(ll g,ll h){
	return g>h;
}
void dfs(ll s,ll k){
	if(s>=m){
		ans=max(ans,k);
		return;
	}
	if(x[s]<ans) return;
	for(int i=1;i<=a;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(s+1,k&x[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&a,&m);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	sort(x+1,x+a+1,cmp);
	for(int i=1;i<=32;i++) p*=2;
	dfs(0,p-1);
	printf("%lld",ans);
	return 0;
}
