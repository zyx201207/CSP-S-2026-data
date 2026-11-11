#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,ans=0;
int a[N],m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int j=1;
	unsigned long long sum=0;
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-j);
		while(sum>m){
			sum-=(a[i]-a[j]);
			j++;
		}
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
}/*
5 5
1 2 4 8 9
*/
