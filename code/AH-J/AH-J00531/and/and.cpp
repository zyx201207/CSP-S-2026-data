#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans;
void dfs(ll x,ll num,ll And){
	if(And<ans)return;
	if(num==m){
		ans=And;
		return;
	}if(x==n)return;
	for(ll i=x+1;i<=n;i++)
		dfs(i,num+1,(num?(And&a[i]):a[i]));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",a+i);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
