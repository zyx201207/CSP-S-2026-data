#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans;
ll a[200009];
void dfs(const ll p,const ll add,const ll t){
	if(add>m||add+n-p+1<m) return ;
	if(t<ans) return ;
	if(p==n+1) {
		ans=t;
		//cout<<ans<<endl;
		return ;
	}
	//cout<<p<<" "<<add<<" "<<t<<endl;
	dfs(p+1,add,t);
	dfs(p+1,add+1,t&a[p]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,greater<ll>());
	//cout<<"a"<<endl;
	dfs(1,0,LLONG_MAX);
	printf("%lld",ans);
	return 0;
}
/*

*/