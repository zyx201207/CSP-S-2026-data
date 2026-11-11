//GZ-S00326 遵义市南白中学 陈梓睿 
#include <bits/stdc++.h>
#define ll long long
#define M 500050
using namespace std;
ll a[M],n,m,pr[M],ans = 1;
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	pr[0] = 0;
	pr[1] = a[1];
	for(ll i = 2;i<=n;i++){
		pr[i] = pr[i-1]+a[i];
	}
	for(ll i = 1;i<=n;i++){
		if(i>ans&&(pr[i]-pr[i-ans]+m)<=ans*a[i]) continue;
		for(ll j = 1;j<=i;j++){
			if((i-j+1)<=ans) break;
			if((m+pr[i]-pr[j-1])>=(i-j+1)*a[i]){
				ans = max(ans,(i-j+1));
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
