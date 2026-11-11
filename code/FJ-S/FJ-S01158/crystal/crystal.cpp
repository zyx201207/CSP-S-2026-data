#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int n; ll m , a[500005] , b[500005];

int main(void){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
//	freopen("crystal1.in" , "r" , stdin);
	scanf("%d%lld" , &n , &m);
	for(int i = 1;i <= n;i++) scanf("%lld" , &a[i]);
	sort(a + 1 , a + 1 + n);
	for(int i = 1;i <= n;i++) b[i] = a[i] + b[i - 1];
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int l = 1 , r = i , ret = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(a[i] * (i - mid) - (b[i - 1] - b[mid - 1]) <= m){
				ret = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ans = max(ans , i - ret + 1);
	}
	printf("%d\n" , ans);
	return 0;
} 
