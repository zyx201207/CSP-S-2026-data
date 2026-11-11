#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],pre[500005],ans = 0,flg = 0,now = 1,otp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i <= n;i++)scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	for(ll i = 1;i <= n;i++)pre[i] = pre[i - 1] + a[i];
	for(ll i = 2;i <= n;i++){
		ans += (a[i] - a[i - 1]) * (i - 1);
		if(ans > m){
			flg = i;
			break;
		}
	}
	if(!flg)printf("%lld",n);
	else{
		otp = flg - 1;
		for(ll i = flg;i <= n;i++){
			while(now <= i && a[i] * (i - now + 1) - pre[i] + pre[now - 1] > m)now++;
			if(now <= i)otp = max(otp,i - now + 1);
		}
		printf("%lld",otp);
	}
	return 0;
}
