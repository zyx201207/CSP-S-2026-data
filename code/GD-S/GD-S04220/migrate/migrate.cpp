#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 20;
#define ll long long
int my_id,T;
ll n,d,a[N];
ll dp[N],dp2[N];
ll my_q[N][3];
ll cnt[N];
int l = 1,r = 0;
void my_add(int x,int y){
	my_q[++r][1] = x;
	my_q[r][2] = y;
	return ;
}
void my_func1(){
	my_q[l][1] = my_q[l][2] = 0;
	
	++l;
	return ;
}
void my_func2(){
	my_q[r][1] = my_q[r][2] = 0;
	--r;
	return ;
}
bool my_check(){
	return (l > r);
}
void my_func3(){
	for(int i = l;i <= r;i++){
		my_q[i][1] = my_q[i][2] = 0;
	}
	l = 1,r = 0;
	return ;
}
void solve(){
	scanf("%lld%lld",&n,&d);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	ll answ =0ll;
	if(n <= 300){
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				dp[j] = 1000000000000000000ll;
				dp2[j] = 0ll;
			}
			dp[i] = 0;
			dp2[i] = 1;
			for(int j = i + 1;j <= n;j++){
				ll mx = 1000000000000000000ll,mx_cnt = 0ll;
				for(int k = i;k < j;k++){
					if(abs(a[k] - a[j]) <= d){
						if(dp[k] + 1ll < mx){
							mx = dp[k] + 1ll;
							mx_cnt = dp2[k];
						}else if(dp[k] + 1ll == mx){
							mx_cnt += dp2[k];
						}
					}
				}
				dp[j] = mx;
				dp2[j] = mx_cnt;
			}
			for(int j = i + 1;j <= n;j++){
				if(dp2[j] == 2){
					answ++;
				}
			}
		}
		printf("%lld\n",answ);
	}else if(n <= 5000){
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				dp[j] = 1000000000000000000ll;
				dp2[j] = 0ll;
			}
			dp[i] = 0;
			dp2[i] = 1;
			my_add(0ll,i);
			int my_L = i;
			cnt[0]++;
			for(int j = i + 1;j <= n;j++){
				while(my_L < j && abs(a[my_L] - a[j]) > d){
					cnt[dp[my_L]] -= dp2[my_L];
					my_L++;
				}
			
				while(!my_check() && my_q[l][2] < my_L){
					my_func1();
				}
			
				if(!my_check()){
					dp[j] = my_q[l][1] + 1ll;
					dp2[j] = cnt[my_q[l][1]];
				
				}
				else break;
				while(!my_check() && my_q[r][1] > dp[j]){
					my_func2();
				}
				cnt[dp[j]] += dp2[j];
				my_add(dp[j],j);
			}
			for(int j = i + 1;j <= n;j++){
				if(dp2[j] == 2){
					answ++;
				}
			}
			my_func3();
			for(int j = 0;j <= n;j++) cnt[j] = 0ll;
		}
		printf("%lld\n",answ);
		
	}
	else if(my_id >= 11 && my_id <= 12){
		if(n == 1) printf("0\n");
		else{
			if(abs(a[2] - a[1]) > d){
				printf("0\n");
			}else{
				ll my_tmp_d = abs(a[2] - a[1]);
				ll tmp_mx = (d / my_tmp_d);
				
				if(tmp_mx == 1){
					printf("0\n");
				}else{
					for(int i = 1;i <= n;i++){
						int my_lst = i + tmp_mx + 1ll;
						if(my_lst <= n) answ += (1ll + (n - my_lst) / tmp_mx);
					}	
					printf("%lld\n",answ);
				}
				
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> my_id >> T;
	while(T--){
		solve();
	}
}
