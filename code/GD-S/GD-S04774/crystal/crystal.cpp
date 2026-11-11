#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll n,m,a[500010],pre[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	pre[1]=a[1];
	ll l=1;
	for(ll i=2;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		while(l<i&&m<(i-l)*a[i]-(pre[i-1]-pre[l-1]))l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
