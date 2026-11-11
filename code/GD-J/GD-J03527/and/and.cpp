#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],n,m,ans=LLONG_MIN;
struct node{
	ll d,sum,p;
	friend bool operator<(const node& a,const node& b){return 1;}
};
map<node,bool> vis;
void dfs(ll depth,ll sum,ll pos){
	if(vis[{depth,sum,pos}]) return;
	vis[{depth,sum,pos}]=1;
	if(depth==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=pos+1;i<=n;i++) dfs(depth+1,(sum&a[i]),i);
}
int main(){
	//freopen("and3.in","r",stdin);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	bool A=1;
	for(int i=1;i<=n;i++){
		scanf(" %lld",a+i);
		if((ll)log2(a[i])!=log2(a[i])) A=0;
	}
	if(!A) dfs(0,-1,0);
	else{
		sort(a+1,a+n+1,greater<int>());
		for(int i=1;i<=m;i++) ans=(ans&a[i]);
	}
	printf("%lld",ans);
	return 0;
}//TLE on #ex4,#ex5
