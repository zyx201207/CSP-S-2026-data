#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const ll N=5e5+7;
ll n,m,ans=1,a[N],arr[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		arr[i]=arr[i-1]+a[i];
	}
	ll l=1;
	for(ll i=1;i<=n;i++){
		while(((arr[i]-arr[l-1]+m)/(i-l+1))<a[i]&&l<=i)l++;
		if(((arr[i]-arr[l-1]+m)/(i-l+1))>=a[i]){
			ans=max(i-l+1,ans);
		}
	}
	cout << ans;
	return 0;
}
