#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5+7;
long long n,m,ans = -1;
long long arr[N];
bool cmp(long long a,long long b){
	return a < b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i = 1;i<=n;i++)	scanf("%lld",&arr[i]);
	sort(arr+1,arr+n+1,cmp);
	long long l = 1,r = 1,num = 0;
	while(r <= n){
		while(num > m)
			num -= arr[r] - arr[l++];
		ans = max(ans,r-l+1);
		num += (arr[r+1]-arr[r]) * (r-l+1);
		r++;
	}
//	if(num <= m)	ans = max(ans,r-l+1);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
