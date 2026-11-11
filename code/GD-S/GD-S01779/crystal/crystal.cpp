#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,b[500005];
bool ch(int x){
	long long t = 0,mn = 1e14;
	for(int i = 1;i + x - 1 <= n;i++){
		for(int j = i;j - i + 1 < x;j++){
			t += a[j] * (j - i + 1);
			printf("%lld ",t);
		}
		printf("\n");
		mn = min(mn,t);
		t = 0;
	}
	return mn <= m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	bool flag = 1;
	for(int i = 1;i < n;i++){
		b[i] = a[i+1] - a[i];
		if(b[i] != b[i-1] && i > 1){
			flag = 0;
		}
	}
	if(flag){
		int sum = 0;
		for(int i = 1;i <= n;i++){
			m -= b[1] * i;
			if(m >= 0){
				sum++;
			}
			else{
				break;
			}
		}
		printf("%d",sum+1);
		return 0;
	}
	int l = 1,r = n,mid;
	while(l <= r){
		mid = (l + r) / 2;
		if(ch(mid)){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	printf("%d",r);
	return 0;
}

