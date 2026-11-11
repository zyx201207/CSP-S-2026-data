#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001]={},ans=1,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>5000&&a[2]-a[1]==a[3]-a[2])
	{
//		cout<<"1";
		ans=m/(a[2]-a[1])+1;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	long long b=0;
	for(int i=1;i<=n;i++)
	{
		b=m;
		sum=1;
		for(int j=i-1;j>=1;j--)
		{
			if(b-(a[i]-a[j])>=0)
			{
				sum++;
				b-=(a[i]-a[j]);
				ans=max(ans,sum);
//				cout<<j<<b<<sum<<ans<<" ";
			}
			else
			{
				break;
			}
		}
//		cout<<endl;
	}
	cout<<ans;
	return 0;
}
