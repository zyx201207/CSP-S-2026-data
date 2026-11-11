#include<bits/stdc++.h>
using namespace std;
int n,f=1,ww=1,ans=1;
long long a[500001],c,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		c+=(a[i]-a[i-1])*ww;
		ww++;
		if(c>m)
		{
			while(c>m)
			{
				c-=a[i]-a[f];
				ww--;
				f++;
			}
		}
		ans=max(ww,ans);
	}
	cout<<ans<<endl;
	return 0;
}
