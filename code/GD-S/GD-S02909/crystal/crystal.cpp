#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=1;
	int sum=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i-1]&&m>=abs(a[i]-a[i-1])*ans)
		{
			sum++;
			m-=abs(a[i]-a[i-1])*ans;
			ans++;
		}
		else if(a[i]==a[i-1])
		{
			ans++;
			sum++;
		}
		else
		{
			break;
		}
	}
	if(sum==0)
	{
		cout<<"0";
	}
	else
	{
		cout<<sum+1;
	}
	return 0;
}
