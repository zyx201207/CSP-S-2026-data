#include<bits/stdc++.h> 
using namespace std;
const int N=10000005;
long long c,t;
long long n,k;
long long a[N];
long long ans1,ans2;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n-1;i++) scanf("%lld",&a[i]);
		ans1=a[1],ans2=a[2];
	}
	printf("%ld\n%ld",ans1,ans2);
	return 0;
} 
