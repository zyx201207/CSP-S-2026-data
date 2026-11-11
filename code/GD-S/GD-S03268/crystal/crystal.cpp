#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i] = abs(a[i]-a[i-1]);
	}
	long long max_len = 0,len = 0,now_m = 0,l = 1,r = 1;
	while(r != n+1){
		if(now_m <= m){
			r++,len++;
			now_m +=len * b[r];
		}
		while(now_m > m){
			now_m -= a[r]-a[l];
			l++,len--;
		}
		max_len = max(max_len,len);
	}
	cout << max_len+1;
	return 0; 
} 
