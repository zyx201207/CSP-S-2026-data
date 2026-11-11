#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	sort(a+1,a+n+1);
	long long cnt=1;
	for(int i=n-1;cnt!=m&&i>=1;i--)
	{
		if(a[i]&ans!=0)
		{
			ans&=a[i];
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}
