#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],book[200005];
ll p,maxn=0;
void dfs(ll st,ll step){
	if(step==m){
		maxn=max(maxn,p);
		return;
	}
	for(ll i=st+1;i<=n;i++){
		if(book[i]==0){
			ll e=p;
			p&=a[i];
			book[i]=1;
			dfs(i,step+1);
			p=e;
			book[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		p=a[i];
		dfs(p,1);
	}
	dfs(1,1);
	printf("%lld",maxn);
	return 0;
}

