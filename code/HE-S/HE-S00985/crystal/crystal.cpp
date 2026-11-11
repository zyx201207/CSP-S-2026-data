#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,sum=1,b[500005];
int n;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ml=m,p=1;
	for(int i=2;i<=n;i++)
	{
		int ll=0;
		if(a[i]==a[i-1])
		{
			sum++;
			b[i]=sum;
			continue;
		}
		if(ml>0&&(a[i]-a[i-1])*sum<=ml)
		{
			ml=ml-(a[i]-a[i-1])*sum;
			sum++;
		}
		else
		{
			ml+=a[i-1]-a[p];
			p++;
			sum--;
			ll=1;
		}
		b[i]=sum;
		if(ll==1)i--;
	}
	sum=1;
	for(int i=1;i<=n;i++)
	{
		sum=max(b[i],sum);
	}
	cout<<sum;
	return 0;
}

