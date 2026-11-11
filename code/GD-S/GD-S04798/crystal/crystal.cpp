#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxx,k;
bool pd;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(k==0)k=a[i];
		if(a[i]-a[i-1]!=k)pd=1;
	}
	if(pd==0)
	{
		long long l=0,sum=0;
		for(int i=0;i<=n-1;i++)
		{
			l=k*i;
			if(m>=l)m-=l,sum++;
			else {cout<<sum;return 0;}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		long long k=m,sum=1;
		for(int j=i-1;j>=1;j--)
		{
			if(k>=(a[i]-a[j]))sum++,k-=(a[i]-a[j]);
			else break;
		}
		maxx=max(maxx,sum);
	}
	cout<<maxx;
	return 0;
}
