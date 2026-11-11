#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL a[500005];
LL m;
int n;
bool check(LL x){
	LL cnt = 0;
	for(int i=1; i<=n; i++){
		if(a[i]>x)continue;
		cnt += x - a[i];
	}
	return cnt <= m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	LL l = 0, r = 1e12+1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
//	cout << r;
	LL ans=0;
	for(int i=1; i<=n; i++){
		if(a[i]>r)continue;
		ans++;
	}
	printf("%lld", ans);
	return 0;
} 
