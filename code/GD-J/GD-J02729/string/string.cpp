#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long sum=0,n,a[N],dns=1,ans=0,b=0;
char c[N],s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		a[i]=sum+a[i];
		sum=a[i];
	}
	for(int i=1;i<=sum;i++)
	{
		if(i<=a[dns])
		{
			s[i]=c[dns];
		}
		else
		{
			dns++;
			s[i]=c[dns];
		}
		if(sum%2==1)
		{
			b=1;
		}
		if(i>sum/2+b)
		{
			if(s[i]!=s[sum-i])
			{
				ans++;
			}
		}
	}
	cout<<ans;
}