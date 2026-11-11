#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	long long cnt=a[2]-a[1];
	ans2=m/cnt+1;
	if(ans2>n)printf("%d",n);
	else printf("%lld",ans2);
	return 0; 
}
