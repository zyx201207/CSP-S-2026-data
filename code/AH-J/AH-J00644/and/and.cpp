#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],maxn;
bool vis[5000010];
void dfs(ll cnt,ll x){
	if(cnt==m) maxn=max(maxn,x);
	for(ll i=1;i<=n;i++){
		if(!vis[i]&&a[i]>maxn){
			vis[i]=1;
			dfs(cnt+1,x&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
	}
	if(n+m<=4000)dfs(0,4194303);
	else{
		maxn=4194303;
		sort(a+1,a+n+1);
		for(ll i=n;i>=n-m;i--){
			maxn=maxn&a[i];
		}
	}
	cout<<maxn;
	return 0;
}
