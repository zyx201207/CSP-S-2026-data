#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l,r,a[200005],len,need;
	char c[200005];
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		cin >> c[i];
		len += a[i];
	}
	l = 1;
	r  = n;
	while(l <= r){
		if(l == r){
			break;
		}
		else{
			if(a[l] > a[r]){
				if(c[l] == c[r]){
					a[l] -= a[r];
				}
				else{
					need += a[r];
					a[l] -= a[r];
				}
				r--;
			}
			else if(a[l] < a[r]){
				if(c[l] == c[r]){
					a[r] -= a[l];
				}
				else{
					need += a[l];
					a[r] -= a[l];
				}
				l++;
			}
			else{
				if(c[l] != c[r]){
					need += a[l];
				}
				r--;
				l++;
			}
		}
	}
	printf("%lld",need);
	return 0;
}
