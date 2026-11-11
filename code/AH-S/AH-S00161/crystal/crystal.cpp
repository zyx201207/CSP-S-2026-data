#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=5e5+5;
long long n,m,a[MAXN],sum[MAXN],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	long long l=1,r=1;
	while(r<=n)
	{
		while(l<=r&&a[r]*(r-l+1)-(sum[r]-sum[l-1])>m) l++;
		ans=max(ans,r-l+1);
		r++;
	}
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	//cout<<"\n";
	cout<<ans<<"\n";
	return 0;
}//Oct31==Dec25?
