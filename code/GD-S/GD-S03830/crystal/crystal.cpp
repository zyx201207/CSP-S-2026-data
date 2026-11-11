#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	long long x=a[1],y=1,ans=0;
	for(int i=1;i<n;i++)
	{
		long long xx=a[i+1]-x;
		while(m<xx*y)
		{
			m=m+(x-a[i-y+1]);
			y--;
		}
		if(xx*y<=m)
		{
			m=m-(xx*y);
			x=a[i+1];
			y++;
//			cout<<i<<": "<<y<<endl;
			ans=max(ans,y);
		}
	}
	cout<<ans<<endl;
	return 0;
}
