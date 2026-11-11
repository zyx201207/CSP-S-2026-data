#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010];

long long summ(long long x){
	long long shu = 0;
	long long sum = 0;
	long long abc = 0;
	for(long long i = 1;i <= n;i++){
		if(a[i] > x){
			abc = i - 1;
			break;
		}
	}
	for(long long i = abc;i >= 1;i--){
		if(sum + x - a[i] <= m){
			sum += x - a[i];
			shu++;
		}else{
			break;
		}
	}
	return shu;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	long long L = a[1],R = a[n];
	long long ans = 0; 
	while(L < R){
		long long mid = (L + R) / 2;
		long long aaa = 0;
		aaa = summ(mid);
		printf("%d %d %d\n",L,R,mid);
		if(aaa > ans){
			L = mid - 1;
			ans = max(ans,aaa);
		}else{
			R = mid;
		}
	}
	printf("%lld",ans);
}
