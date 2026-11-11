#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxa=-1,maxn=-1,ans=0b1111111111111111111111111111111,a[200010];
bool vis[200010];
void dfs(ll cnt,ll sum){
	if(cnt==m){
		maxn=max(maxn,sum);
		return;
	}	
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(cnt+1,sum&a[i]);
			vis[i]=0;
		}
	}	
}	
void try25(){
	dfs(0,0b1111111111111111111111111111111);
	printf("%lld",maxn);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	bool ok=false;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxa=max(maxa,a[i]);
		double k=log2(a[i]+1);
		ll kk=k;
		if(kk!=k) ok=false;
	}	
	if(ok){
		sort(a+1,a+n+1);
		printf("%lld",a[n-m+1]);
	}	
	else if(m==1) printf("%lld",maxa);
	else if(m==n){
		for(ll i=1;i<=n;i++){
			ans=ans&a[i];
		}	
		printf("%lld",ans);
	}	
	else if(m==2){
		maxa=-1;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				maxa=max(maxa,a[i]&a[j]);
			}	
		}	
		printf("%lld",maxa);
	}	
	else if(m==n-1){
		maxn=-1;
		for(ll i=1;i<=n;i++){
			ans=0b1111111111111111111111111111111;
			for(ll j=1;j<=n;j++){
				if(i==j) continue;
				ans&=a[j];
			}	
			maxn=max(maxn,ans);
		}	
		printf("%lld",maxa);
	}
	else if(n<=20) try25();
	else printf("0");
	return 0;
}
