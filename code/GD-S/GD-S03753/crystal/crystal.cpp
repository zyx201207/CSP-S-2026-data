#include <iostream>
#include <algorithm>
using namespace std;
long long l=1,n,m;
long long need,ans=1;
long long a[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		need+=(a[i]-a[i-1])*(i-l);
		while(need>m)need-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
} 
