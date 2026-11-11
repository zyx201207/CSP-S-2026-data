#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500005];
long long sm[500005];
int res = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",a + i);
		//sm[i] = sm[i - 1] + a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) sm[i] = sm[i - 1] + a[i];
	for(int i = 1;i <= n;i++){
		int l = 1,r = i,ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if((long long)(i - mid + 1) * a[i] - (sm[i] - sm[mid - 1]) <= m) ans = mid,r = mid - 1;
			else l = mid + 1; 
		}
		res = max(res,i - ans + 1);
	}
	printf("%d",res);
	return 0;
}
