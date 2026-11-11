#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif
ll r(){
	ll f=1,k=0,c=gc();
	for(;!isdigit(c);c=gc())	if(c == '-')	f = -1;
	for(;isdigit(c);c=gc())		k=k*10+(c&15);
	return f*k;
}
ll n,m;
ll a[500005];//原数组 
ll sum[500005];// d的前缀和 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	sum[1] = sum[0] = 0;//这位以前所有的数 与 这位数的差 
	ll ans = 1;//答案 
	ll l=1;//m - 差分的前缀[l] 
	for(ll i=2;i<=n;i++){
		ll d = (a[i]-a[i-1]);
		sum[i] = sum[i-1] + d*(i-1);
		while(m - (sum[i] - sum[l] + d*(l-1)) < 0){
			l++;
		}
		ll last_ans = (i-l+1);
		ans = max(ans,last_ans);
	} 
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
