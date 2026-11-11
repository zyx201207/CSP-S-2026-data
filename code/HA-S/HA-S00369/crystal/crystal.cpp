#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],sum,w,ans;
int b[1000010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	if(a[1]==a[n])
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	b[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++)
	{
		if(b[1]==b[i])
		sum++;
	}
	if(sum==n-1)
	{
		while(w<=m)
		{
			ans++;
			w+=b[1]*ans;
			
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(w<=m)
		{
//			a[i]+=b[i];
			w+=b[i]*i;
		}
//		if(i==n&&w==m)
//		{
//			cout<<i+1;
//			return 0;
//		}
		else
		{
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}
