#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll lis[555555];
ll qzh[555555];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> lis[i];
	}
	sort(lis+1,lis+1+n);
	for(int i = 1;i <= n;i++){
		qzh[i] = qzh[i-1] + lis[i];
	}
	
	ll ma = 1;
	for(int i = 1;i <= n;i++){
		ll l = 1;
		ll r = i;
		while(l < r){
			ll mid = (l+r)/2;
			ll opt = lis[i]*(i-mid+1) - (qzh[i] - qzh[mid-1]);
			if(opt > m){
				l = mid+1;
			}
			else{
				r = mid;
			}
		}
		ma = max(ma,i-r+1);
	}
	cout << ma;
	return 0;
}