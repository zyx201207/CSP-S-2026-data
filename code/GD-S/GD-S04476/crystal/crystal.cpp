#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,m,max_ans = -1;
ll a[500010];
ll func_f(ll x,ll i){
	for(int j = i;j < n;j++)if(a[j]>x)return j;
	return -1;
}
ll funcf(ll x,ll i){
	for(int j = i;j < n;j++)if(a[j]>x)return j-1;
	return n-1;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	cin >> a[0];
	for(int i = 1;i < n;i++)cin >> a[i];
	sort(a,a+n);
	for(int i = 0;i < n;i++){
		ll x=m,ad_dr=i;
		ll nxtad=func_f(a[i],i);
		if(nxtad!=-1){
			while(x>=(nxtad-i)*(a[nxtad]-a[ad_dr])){
				x-=(nxtad-i)*(a[nxtad]-a[ad_dr]);
				ad_dr = nxtad;
				if(func_f(a[nxtad],nxtad)!=-1){
					nxtad=func_f(a[nxtad],nxtad);
				}
				else{
					break;
				}
			}
		}
		ll cnt=funcf(a[ad_dr],ad_dr)-i+1;
		if(max_ans<cnt)max_ans=cnt;
		if(max_ans>=n-1-i)break;
	}
	cout << max_ans;
	return 0;
}
