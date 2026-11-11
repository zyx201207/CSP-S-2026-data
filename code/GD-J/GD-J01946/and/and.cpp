#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

ll ans=0,a[100005];
ll n,m;
vector<bool> v(100005,false);

void dfs(ll cnt,ll sum){
	if(cnt==m){
		ans=max(ans,sum);
	}
	for(ll i=1;i<=n;i++){
		if(!v[i]){
			v[i]=true;
			dfs(cnt+1,sum&a[i]);
			v[i]=false;
		}
	}
	return;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,((1<<30)-1));
	
	printf("%lld",ans);
	return 0;
}
