#include<iostream>
#include<algorithm>
using namespace std;
long long a[500001],n,m;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a,a+n+1);
	for(int i=1;i<n;i++)
	a[i]=a[i+1]-a[i];
	a[n]=0;
	int l=1,r=n;
	while(1)
	{
		if(l==r)
		
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
			else
			r=mid-1;
	}
	return 0;
 } 
