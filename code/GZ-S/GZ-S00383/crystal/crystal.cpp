//GZ-S00383 北京师范大学贵阳附属中学 杨然
#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[9001001],ans,sum,b[9001001],ma = -1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[a[i]]++;
		if(b[a[i]] > ma)ma = b[a[i]];
		sum+=a[i];
	}
	ans+=ma;
	sort(a+1,a+1+n);
	if(a[1]==a[n]){
		printf("%lld",n);
		return 0;
	}
	long long l = n;	
    while(a[l]*(l-1) - sum > m){
    	l--;
    	sum-=a[l];
    	if(a[l] < 0)sum += a[l];
	}
	ans+=l-ans;
	printf("%lld",ans);
	return 0;
}
