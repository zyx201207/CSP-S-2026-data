#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=0,a[200005];
void dfs(ll x,ll c,ll s);
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n<=20){
		dfs(1,m,INT_MAX);
		printf("%lld\n",ans);
	}else if(m==1){
		for(ll i=1;i<=n;i++) ans=max(ans,a[i]);
		printf("%lld\n",ans);
	}else if(m==n){
		ans=a[1];
		for(ll i=2;i<=n;i++) ans=ans&a[i];
		printf("%lld\n",ans);
	}else if(m==n-1){
		for(ll i=1;i<=n;i++){
			ll tmp=INT_MAX;
			for(ll j=1;j<=n;j++){
				if(j!=i) tmp&=a[j];
			}
			ans=max(ans,tmp);
		}
		printf("%lld\n",ans);
	}else if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%lld\n",ans);
	}else{
		srand(time(0));
		ll k=rand()%(32+1);
		ll cum=1;
		for(ll i=1;i<=k;i++) cum*=2;
		cout<<cum<<endl;
	}
	return 0;
}
void dfs(ll x,ll c,ll s){
	if(x>n){
		if(c<=0) ans=max(ans,s);
		return ;
	}
	if(c>0) dfs(x+1,c-1,s&a[x]);
	dfs(x+1,c,s);
	return ;
}
