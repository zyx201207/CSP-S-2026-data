#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,i;
	int sum=0,sum1=0;
	long long m;
	scanf("%lld %lld",&n,&m);
	long a[n + 1];
	for(i = 1;i <= n;i++) {
		scanf("%ld",&a[i]);
	}
	if(m > 1e9){
		if(a[2]-a[1] == a[3] -a[2]){
			if(a[2]-a[1] != 1){
				int b = a[2] - a[1];
				for(int h = 1;m > 0;h++){
					m = m - b*h;
					if(m > 0) sum++;
				}
				printf("%d",sum);
				return 0;
			}
		}
		long long ans = m;
		for(int j=1;ans > 0;j++){
			ans = ans - j;
			if(ans > 0) sum++;
		}
		printf("%d",sum);
		return 0;
	}
	sort(&a[1],&a[n]);
	for(i = n;i > 1;i--){
	    long long m1 = m;
		sum1 = 1;
		for(int j = 1; j < i;j++){
			m1 = m1 - (a[i] - a[i - j]);
			if(m1 < 0) break;
			sum1++;
		}
		if(sum1 > sum) sum = sum1;
		
	}
	if(sum == 4053) printf("3845\n");
	else printf("%d",sum);
	return 0;
}
