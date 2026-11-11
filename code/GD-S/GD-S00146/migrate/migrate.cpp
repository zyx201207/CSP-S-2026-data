//why 2h on this task
//can I do better? 
#include<bits/stdc++.h>
using namespace std;
int c,t,n,prv[2000009],dp[2000009],dp2[2000009],dp3[2000009];
long long x[2000009],d,ans;
char buf[(1 << 20) + 3],*p1 = buf,*p2 = buf;
#define gc ((p1 == p2) && (p2 = (p1 = buf) + fread(buf,1,(1 << 20),stdin),p2 == p1) ? EOF : *p1 ++)
template<typename T>
void rd(T &x){
	char c = gc;
	x = 0;
	bool f = false;
	while(!isdigit(c) && c != '-')
		c = gc;
	if(c == '-'){
		f = true;
		c = gc;
	}
	while(isdigit(c))
		x = x * 10 - c + '0',c = gc;
	if(!f)
		x = -x;
}
#undef gc
void wt(long long x){
	if(x > 9)
		wt(x / 10);
	putchar(x % 10 + '0');
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	rd(c),rd(t);
	while(t--){
		rd(n),rd(d);
		for(int i = 1; i <= n; i ++){
			rd(x[i]);
		}
		int o = 1;
		prv[1] = 1;
		for(int i = 2; i <= n; i ++){
			while(o < i && x[i] - x[o] > d)
				o ++;
			prv[i] = o;
		//	printf("%d %d\n",i,prv[i]);
		}
		ans = 0;
		for(int i = 1; i <= n; i ++){
			dp3[i] = dp[i] = dp2[i] = 0;
			if(prv[i] == i){
				//dp[i] = 1;
				continue;
			}
			else if(prv[i] == i - 1){
				dp[i] = dp[prv[i]] + 1;
				dp2[i] = dp2[prv[i]];
				ans += dp2[i];
				continue;
			}
			dp[i] = i - prv[prv[i]];
			dp[i] -= prv[i] - prv[prv[i] + 1];
			dp2[i] += prv[prv[i] + 2] - prv[prv[i] + 1],dp3[i] += prv[prv[i] + 2] - prv[prv[i] + 1];
			if(prv[prv[i]] < prv[prv[i] + 1]){
				dp[i] += dp[prv[i]] + prv[prv[i]] - prv[i];
				dp2[i] += dp2[prv[i]] - dp3[prv[i]] * (prv[prv[i]] + 1 == prv[prv[i] + 1]);
			}
			else if(prv[i] > i - 2 || prv[prv[i]] < prv[prv[i] + 2]){
				dp2[i] += dp[prv[i]] + prv[prv[i]] - prv[i];
				dp3[i] += dp[prv[i]] + prv[prv[i]] - prv[i];
			} 
			ans += dp2[i];
		}
		wt(ans);
		puts("");
	}
}
