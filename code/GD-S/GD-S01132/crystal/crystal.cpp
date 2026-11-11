#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N = 5e5 + 10;
long long a[N];
long long cnt=0,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long l=1;
	for(long long i=2;i<=n;i++){
		cnt+=(a[i]-a[i-1])*(i-l);
		while(cnt>m){
			cnt-=(a[i]-a[l]);
			l++;	
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
} 
