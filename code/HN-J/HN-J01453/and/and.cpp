#include<iostream>
#include<algorithm>
using namespace std;
int a[100000];
int n,m,ans=-1000000;
main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if (m==1)
	{
		sort(a,a+n+1);
		cout<<a;
		return 0;
	}
	else{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((a[i]&a[j])>ans)
				ans=(a[i]&a[j]);
		}
	}}
	cout<<ans;
	return 0;
}
