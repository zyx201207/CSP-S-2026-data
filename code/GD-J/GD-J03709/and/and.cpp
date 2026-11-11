#include<iostream>
#include<algorithm>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=a[1];
	if(m==1) cout<<ans<<"\n";
	else if(m==n)
	{
		for(int i=2;i<=n;i++)
			ans=(ans&a[i]);
		cout<<ans<<"\n";
	}
	else if(m==2)
	{
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans<<"\n";
	}
	else cout<<a[m]<<"\n";
	return 0;
}
