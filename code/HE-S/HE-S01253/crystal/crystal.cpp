#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,p,q,s;
int main()
{
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		p=m,s=0;
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]-a[j]>p)
				break;
			p-=(a[i]-a[j]);
			s++;
		}
		ans=max(ans,s);
	}
	cout<<ans+1;
	return 0;
}
