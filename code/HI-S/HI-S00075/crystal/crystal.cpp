#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,minn=1000000000000086,c[500010],h;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	c[1]=0;
	for(int i=2;i<=n;i++)
	{
		c[i]=(a[i]-a[i-1])*(i-1)+c[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		long long num=c[i];
		if(m>=num) ans=m-num;
		else ans=num-m;
		if(minn>ans)
		{
			minn=ans;
			h=i;
		}
	} 
	cout << h;
	return 0;
}
