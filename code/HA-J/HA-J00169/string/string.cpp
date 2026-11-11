#include <bits/stdc++.h>
using namespace std;

struct STRING{
	long long a;
	char b;
}a[2000001];
int n;
long long num1 = 1,num2 = 0;
long long ans = 0;

int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for( int l = 1 ; l <= n ; l++ ){
		scanf("%lld %c",&a[l].a,&a[l].b);
	}
	num2 = n;
	for(;num1 != num2&&num1 < num2; ){
		if(a[num1].b != a[num2].b){
			ans += min(a[num1].a,a[num2].a);
		}
		if(a[num1].a < a[num2].a){;
			a[num2].a -= a[num1].a;
			num1++;
		}
		else{
			if(a[num1].a > a[num2].a){
				a[num1].a -= a[num2].a;
				num2--;
			}
			else{
				num1++;
				num2--;
			}	
		}
	}
	printf("%lld\n",ans);
	return 0;
}
