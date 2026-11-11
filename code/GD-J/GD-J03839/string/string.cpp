#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n,l,r;
	long long ans = 0;
	scanf("%d" ,&n);
	for(int i = 1;i <= n;i++){
		scanf("%d %c" ,&a[i],&c[i]);
	}
	l = 1,r = n;
	while(l <= r){
		if(c[l] == c[r]){
			if(a[l] == a[r]){
				l++;
				r--;
			}else if(a[l] < a[r]){
				a[r] -= a[l];
				l++;
			}else{
				a[l] -= a[r];
				r--;
			}
		}else{
			if(a[l] == a[r]){
				ans += a[l];
				l++;
				r--;
			}else if(a[l] < a[r]){
				ans += a[l];
				a[r] -= a[l];
				l++;
			}else{
				ans += a[r];
				a[l] -= a[r];
				r--;
			}
		}
	}
	printf("%lld" ,ans);
	return 0;
} 
