#include <iostream>
#include <algorithm>
using namespace std;
long long a[500005],sumf[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+1+n);
	int sum=0,cnt=1,ans=1;
	for(int i=2;i<=n;i++){
		sum+=cnt*(a[i]-a[i-1]),cnt++;
		while(sum>m) sum-=a[i]-a[i-cnt+1],cnt--;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
// S00843
// 100pts
