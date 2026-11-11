#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n/2;i++)
	{
		if(c[i]!=c[n-i+1])
		{
			if(a[i]>=a[n-i+1])
			{
				ans+=a[i];
			}
			else ans+=a[n-i+1];
		}
	}
	cout<<ans;
	return 0;
}

