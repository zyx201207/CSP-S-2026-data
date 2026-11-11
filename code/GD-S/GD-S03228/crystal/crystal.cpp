#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 55;
ll n,m,a[N],sum[N],ans = 1;

int emt_bless_me(int rp){return rp++;}

inline ll emt(ll L){
	ll l = L,r = n,mid = (l + r) >> 1;
	while(l <= r){
		mid = (l + r) >> 1;
		if(sum[mid] - sum[L - 1] + m >= 1ll * a[mid] * (mid - L + 1))l = mid + 1;
		else r = mid - 1;
		//cout<<mid<<' ';
	}
	return r - L + 1;
}

int main(){
	cin.tie(nullptr) -> ios_base::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	sort(a + 1,a + n + 1);
	//for(int i = 1;i <= n;i++)cout<<a[i]<<'\n';
	for(int i = 1;i <= n;i++)sum[i] = sum[i - 1] + a[i];
	for(int i = 1;i <= n;i++)ans = max(ans,emt(i));
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4

*/
