#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+15;
long long n, m, i, j, k, a[N], b[N], s[N], ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for(i=1; i<=n; i++){
		b[i]=a[i]-a[i-1];//我和上一个数的差值 
		s[i]=b[i]*(i-1)+s[i-1];
//		printf("b[i]=%lld s[i]=%lld\n", b[i], s[i]);
		if(s[i]<=m) ans=i;
	}
	printf("%lld", ans);
	return 0;
} 
//i      1  2  3  4   5
//a[i]   1  2  4  8   9
//b[i]   1  1  2  4   1
//s[i]   0  1  5  17  21
//i,j        23 24  25
//s[i,j]     2  10  13    
   
//差值为s[i]=b[i]*(i-1)+s[i-1]
