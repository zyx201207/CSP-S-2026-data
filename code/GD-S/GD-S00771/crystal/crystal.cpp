#include<bits/stdc++.h>

using namespace std;
long long n, m, a[1000000];
long long i, j, k;
long long c;
int main(){
	freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(i=0;i<n;++i){
    	scanf("%lld", &a[i]);
	}
	sort(a,a+n);
	for(i=1, k=0;i<n;++i){
		m=m-(a[i]-a[i-1])*(i-k);
		while(m<0){
			m=m+(a[i]-a[k]);
			++k;
		}
		c=max(c, i+1-k);
	}
	printf("%lld", c);
	return 0;
} 
