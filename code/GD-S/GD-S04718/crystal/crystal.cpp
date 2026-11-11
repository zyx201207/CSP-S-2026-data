#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+5;
ll a[N],m,sum[N];
int n;
void init(){
	sum[1] = a[1];
	for(int i=2;i<=n;i++){
		sum[i] = sum[i-1]+a[i];
	}
}
ll ed(ll t,int i,int j){
	return 1ll*t*(j-i)-(sum[j-1]-sum[i-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans = 1;
	int k = 1;
	init();
	for(int i=1;i<=n;i++){
		while(ed(a[i],k,i) > m){
			k++;
			if(k > i){
				cout << 1;
				return 0;
			}
		}
		ans = max(ans,i-k+1);
	}
	cout << ans;
	return 0;
}
