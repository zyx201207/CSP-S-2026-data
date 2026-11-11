#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans=0,a[200005],maxi=0;
bool cmp(ll x,ll y){return x>y;}
void dfs(ll x,ll step,ll i){
	if(step==m) ans=max(ans,x);
	for(int j=i+1;j<=n;j++) dfs(x&a[i],step+1,j);
}
int main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++) cin >>a[i],ans&=a[i],maxi=max(maxi,a[i]);
	sort(a+1,a+n+1,cmp);
	if(m==n){cout<<ans;return 0;}
	if(m==1){cout<<maxi;return 0;}
	for(int i=1;i<=n;i++){
		dfs(a[i],1,i);
	}
	cout<<ans;
	return 0;
}
