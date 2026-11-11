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
const ll N = 2e6+10;
ll c,t,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	c = gc(),t = gc();
	while(t--){
		n = gc(),d = gc();
		for(int i=1;i<=n;i++)x[i] = gc();
		ll dc = (x[n] - x[1]) / (n-1);
		if(dc*2 < d){
			op(0);
			putchar('\n');
		}
		else op((x[n]-x[1])/d),putchar('\n');
	}

	return 0;
}
