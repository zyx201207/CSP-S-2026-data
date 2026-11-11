#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,l = 1,r = 1,ans = 1,len;
	long long m,sum = 0;
	scanf("%d%lld" ,&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld" ,&a[i]);
	}
	sort(a + 1,a + n + 1);
	while(1){
		len = r - l + 1;
		ans = max(ans,len);
		r++;
		if(r > n){
			break;
		}
		sum += (a[r] - a[r - 1]) * len;
		while(sum > m){
			sum -= a[r] - a[l];
			l++;
		}
	}
	printf("%d" ,ans);
	return 0;
}
