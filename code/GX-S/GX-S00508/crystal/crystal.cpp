#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gc(){
	char c = getchar_unlocked();
	ll k = 0,f = 1;
	while(c<'0' || c>'9'){
		if(c == '-')f = -1;
		c = getchar_unlocked();
	}
	while(c>='0' && c<='9')k = k*10+c-'0',c = getchar_unlocked();
	return k*f;
}
void op(ll x){
	if(x < 0)x = -x,putchar('-');
	if(x < 10)putchar(x%10+'0');
	else op(x/10),putchar(x%10+'0');
}
const ll N = 5e5+10;
ll n,m,a[N],sum1[N],sum2[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n = gc(),m = gc();
	for(int i=1;i<=n;i++)a[i] = gc();
	sort(a+1,a+1+n);
	ll l = 1,ans = 0;
	for(int i=1;i<=n;i++)sum1[i] = a[i]+sum1[i-1];
	for(int i=1;i<=n;i++){
		ll len = i-l+1,cnt = sum1[i]-sum1[l-1];
		while(len*a[i]-cnt > m && l<i){
			l++;
			len = i-l+1;
			cnt = sum1[i]-sum1[l-1];
		}
		len = i-l+1;
		ans = max(ans,len);
	}
	op(ans);

	return 0;
}
