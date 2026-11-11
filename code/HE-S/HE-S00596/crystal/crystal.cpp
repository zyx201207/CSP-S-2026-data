#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 }
	sort(a+1,a+n+1);
	a[0]=a[1];
	int l=1;
	long long cnt=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=(a[i]-a[i-1])*(i-1-l+1);
		while(cnt>m)
		{
			cnt-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
